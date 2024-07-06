#include <stdio.h>
#include <SDL2/SDL.h>

#include "./headers/window.h"
#include "./headers/situations.h"
#include "./headers/constants.h"

typedef int bool_t;

int		main (void) {
	bool_t			quit;
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Renderer	*renderer;


	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (1);
	}

	window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
	if (window == NULL) {
		SDL_Quit();
	}

	renderer = render_window(window);
	if (renderer == NULL) {
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	quit = 0;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}

		SDL_SetRenderDrawColor(renderer, 11, 57, 84, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		//situation0(renderer);
		//situation1(renderer);
		//situation2(renderer);
		situation3(renderer);

		SDL_RenderPresent(renderer);

		// approximately 60fps
		// 1000ms / 60 = 16.667
		// we want to have 60fps, so we need to calculate how fast should be one frame in 1second if we want
		// to have 60 frames in that second => 1s / 60frames = 0.016667s = 16.67ms
		SDL_Delay(dt);
	}
	return (0);
}