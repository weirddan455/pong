#include <SDL2/SDL.h>

#define BALL_W 20
#define BALL_H 20

typedef struct GameState {
    SDL_Rect player1;
    SDL_Rect player2;
    SDL_Rect ball;
    int ballxv;
    int ballyv;
    int player1v;
    int player2v;
    int player1Score;
    int player2Score;
    Sint16 *wallSound;
    Sint16 *paddleSound;
    Sint16 *scoreSound;
} GameState;

Sint16* genSquareWave(int samples, int tone) {
    Sint16 *wave = malloc(samples * 4);
    Sint16 *counter = wave;
    int waveLow = 0;
    for (int i = 0; i < samples; i++) {
        if (i % tone == 0) {
            if (waveLow == 0) {
                waveLow = 1;
            } else {
                waveLow = 0;
            }
        }
        Sint16 sampleValue = waveLow ? -3000 : 3000;
        *counter = sampleValue;
        counter++;
        *counter = sampleValue;
        counter++;
    }
    return wave;
}

GameState* initGameState(SDL_Renderer *renderer) {
    GameState *gameState = malloc(sizeof (GameState));

    int rendW, rendH;
    SDL_GetRendererOutputSize(renderer, &rendW, &rendH);
    int centerW = rendW / 2;
    int centerH = rendH / 2;

    int paddleW = 20;
    int paddleH = 50;
    int paddleY = centerH - (paddleH / 2);

    gameState->player1.w = paddleW;
    gameState->player1.h = paddleH;
    gameState->player1.x = 20;
    gameState->player1.y = paddleY;

    gameState->player2.w = paddleW;
    gameState->player2.h = paddleH;
    gameState->player2.x = rendW - paddleW - 20;
    gameState->player2.y = paddleY;

    gameState->ball.w = BALL_W;
    gameState->ball.h = BALL_H;
    gameState->ball.x = centerW - (gameState->ball.w / 2);
    gameState->ball.y = centerH - (gameState->ball.h / 2);

    gameState->ballxv = 5;
    gameState->ballyv = 5;

    gameState->player1v = 0;
    gameState->player2v = 0;
    gameState->player1Score = 0;
    gameState->player2Score = 0;

    gameState->wallSound = genSquareWave(4096, 128);
    gameState->paddleSound = genSquareWave(4096, 16);
    gameState->scoreSound = genSquareWave(16384, 256);

    return gameState;
}

void freeGameState(GameState *gameState) {
    free(gameState->wallSound);
    free(gameState->paddleSound);
    free(gameState->scoreSound);
    free(gameState);
}

void updateGameState(GameState *gameState, SDL_Renderer *renderer, SDL_AudioDeviceID audioDevice) {
    int rendW, rendH;
    SDL_GetRendererOutputSize(renderer, &rendW, &rendH);

    int ballResetX = (rendW / 2) - (gameState->ball.w / 2);
    int ballResetY = (rendH / 2) - (gameState->ball.h / 2);

    // Collision detection for paddle 1 with top and bottom of the screen
    if (gameState->player1.y + gameState->player1v < 0) {
        gameState->player1.y = 0;
        gameState->player1v = 0;
    } else if (gameState->player1.y + gameState->player1v > rendH - gameState->player1.h) {
        gameState->player1.y = rendH - gameState->player1.h;
        gameState->player1v = 0;
    } else {
        gameState->player1.y += gameState->player1v;
    }

    // Collision detection for paddle 2 with top and bottom of the screen
    if (gameState->player2.y + gameState->player2v < 0) {
        gameState->player2.y = 0;
        gameState->player2v = 0;
    } else if (gameState->player2.y + gameState->player2v > rendH - gameState->player2.h) {
        gameState->player2.y = rendH - gameState->player2.h;
        gameState->player2v = 0;
    } else {
        gameState->player2.y += gameState->player2v;
    }

    // Collision detection for ball with top and bottom of the screen
    if (gameState->ball.y + gameState->ballyv < 0) {
        gameState->ball.y = 0;
        gameState->ballyv *= -1;
        SDL_QueueAudio(audioDevice, gameState->wallSound, 4096 * 4);
    } else if (gameState->ball.y + gameState->ballyv > rendH - gameState->ball.h) {
        gameState->ball.y = rendH - gameState->ball.h;
        gameState->ballyv *= -1;
        SDL_QueueAudio(audioDevice, gameState->wallSound, 4096 * 4);
    } else {
        gameState->ball.y += gameState->ballyv;
    }

    // Check if a player scored. If not, check collision between ball and paddles.
    if (gameState->ball.x < 0) {
        gameState->player2Score++;
        printf("Player 2 scores.\nPlayer 1 Score: %d\nPlayer 2 Score: %d\n", gameState->player1Score, gameState->player2Score);
        gameState->ball.w = BALL_W;
        gameState->ball.h = BALL_H;
        gameState->ball.x = ballResetX;
        gameState->ball.y = ballResetY;
        SDL_QueueAudio(audioDevice, gameState->scoreSound, 16384 * 4);
    } else if (gameState->ball.x + gameState->ball.w > rendW) {
        gameState->player1Score++;
        printf("Player 1 scores.\nPlayer 1 Score: %d\nPlayer 2 Score: %d\n", gameState->player1Score, gameState->player2Score);
        gameState->ball.w = BALL_W;
        gameState->ball.h = BALL_H;
        gameState->ball.x = ballResetX;
        gameState->ball.y = ballResetY;
        SDL_QueueAudio(audioDevice, gameState->scoreSound, 16384 * 4);
    } else if (gameState->ball.x + gameState->ballxv <= gameState->player1.x + gameState->player1.w
            && gameState->ball.y + gameState->ball.w >= gameState->player1.y
            && gameState->ball.y <= gameState->player1.y + gameState->player1.h) {
        gameState->ball.x = gameState->player1.x + gameState->player1.w + 1;
        gameState->ballxv *= -1;
        SDL_QueueAudio(audioDevice, gameState->paddleSound, 4096 * 4);
    } else if (gameState->ball.x + gameState->ballxv + gameState->ball.w >= gameState->player2.x
            && gameState->ball.y + gameState->ball.w >= gameState->player2.y
            && gameState->ball.y <= gameState->player2.y + gameState->player2.h) {
        gameState->ball.x = gameState->player2.x - gameState->ball.w - 1;
        gameState->ballxv *= -1;
        SDL_QueueAudio(audioDevice, gameState->paddleSound, 4096 * 4);
    } else {
        gameState->ball.x += gameState->ballxv;
    }
}

void renderFrame(GameState *gameState, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &gameState->player1);
    SDL_RenderFillRect(renderer, &gameState->player2);
    SDL_RenderFillRect(renderer, &gameState->ball);
    SDL_RenderPresent(renderer);
}

int main (int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        printf("Failed to initalize SDL. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, 0);
    if (window == NULL) {
        printf("Failed to create window. SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    if (renderer == NULL) {
        printf("Failed to create renderer. SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_AudioSpec want, have;
    want.freq = 48000;
    want.format = AUDIO_S16LSB;
    want.channels = 2;
    want.samples = 4096;
    want.callback = NULL;
    SDL_AudioDeviceID audioDevice = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
    SDL_PauseAudioDevice(audioDevice, 0);

    GameState *gameState = initGameState(renderer);
    renderFrame(gameState, renderer);

    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_w:
                            gameState->player1v = 0;
                            break;
                        case SDLK_s:
                            gameState->player1v = 0;
                            break;
                        case SDLK_UP:
                            gameState->player2v = 0;
                            break;
                        case SDLK_DOWN:
                            gameState->player2v = 0;
                            break;
                    }
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_w:
                            gameState->player1v = -5;
                            break;
                        case SDLK_s:
                            gameState->player1v = 5;
                            break;
                        case SDLK_UP:
                            gameState->player2v = -5;
                            break;
                        case SDLK_DOWN:
                            gameState->player2v = 5;
                            break;
                    }
                    break;
                case SDL_QUIT:
                    freeGameState(gameState);
                    SDL_DestroyRenderer(renderer);
                    SDL_DestroyWindow(window);
                    SDL_Quit();
                    return 0;
            }
        }
        updateGameState(gameState, renderer, audioDevice);
        renderFrame(gameState, renderer);
        SDL_Delay(10);
    }
}
