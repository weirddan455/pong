#ifndef _SCORE_H
#define _SCORE_H

#include <SDL2/SDL.h>

#define SCORE_W 50
#define SCORE_H 100

void updateScoreTex(int score, SDL_Texture **tex1, SDL_Texture **tex2, SDL_Texture *textures[]);

SDL_Texture* genTex0(SDL_Renderer *renderer);
SDL_Texture* genTex1(SDL_Renderer *renderer);
SDL_Texture* genTex2(SDL_Renderer *renderer);
SDL_Texture* genTex3(SDL_Renderer *renderer);
SDL_Texture* genTex4(SDL_Renderer *renderer);
SDL_Texture* genTex5(SDL_Renderer *renderer);
SDL_Texture* genTex6(SDL_Renderer *renderer);
SDL_Texture* genTex7(SDL_Renderer *renderer);
SDL_Texture* genTex8(SDL_Renderer *renderer);
SDL_Texture* genTex9(SDL_Renderer *renderer);

#endif
