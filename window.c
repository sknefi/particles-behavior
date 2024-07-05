#include <SDL2/SDL.h>
#include <stdio.h>

SDL_Window	*create_window(const int x, const int y) {
	SDL_Window* window = SDL_CreateWindow("PARTICLES",
									  SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED,
									  x,
									  y,
									  SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	return (window);
}

SDL_Renderer	*render_window(SDL_Window *window) {
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	return (renderer);
}