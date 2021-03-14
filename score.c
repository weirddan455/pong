#include <SDL2/SDL.h>
#include "score.h"

void updateScoreTex(int score, SDL_Texture **tex1, SDL_Texture **tex2, SDL_Texture *textures[]) {
    if (score > 99 || score < 0) {
        *tex1 = textures[0];
        *tex2 = textures[0];
    } else {
        *tex1 = textures[score / 10];
        *tex2 = textures[score % 10];
    }
}

SDL_Texture* genTex0(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 20;
    rect.h = SCORE_H - 20;
    rect.x = 10;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture* genTex1(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    rect.w = 10;
    rect.h = SCORE_H;
    rect.x = SCORE_W - 10;
    rect.y = 0;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture* genTex2(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 10;
    rect.h = 35;
    rect.x = 0;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    rect.x = 10;
    rect.y = 55;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture *genTex3(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 10;
    rect.h = 35;
    rect.x = 0;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    rect.y = 55;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture *genTex4(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 20;
    rect.h = 45;
    rect.x = 10;
    rect.y = 0;
    SDL_RenderFillRect(renderer, &rect);
    rect.w = SCORE_W - 10;
    rect.x = 0;
    rect.y = 55;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture *genTex5(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 10;
    rect.h = 35;
    rect.x = 10;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    rect.x = 0;
    rect.y = 55;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture *genTex6(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 10;
    rect.h = 35;
    rect.x = 10;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    rect.w = SCORE_W - 20;
    rect.y = 55;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture* genTex7(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 10;
    rect.h = SCORE_H - 10;
    rect.x = 0;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture *genTex8(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 20;
    rect.h = 35;
    rect.x = 10;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    rect.y = 55;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}

SDL_Texture *genTex9(SDL_Renderer *renderer) {
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCORE_W, SCORE_H);
    SDL_Rect rect;
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    rect.w = SCORE_W - 20;
    rect.h = 35;
    rect.x = 10;
    rect.y = 10;
    SDL_RenderFillRect(renderer, &rect);
    rect.w = SCORE_W - 10;
    rect.x = 0;
    rect.y = 55;
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderTarget(renderer, NULL);
    return texture;
}
