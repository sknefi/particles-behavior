#include <stdio.h>
#include <SDL2/SDL.h>

#include "./headers/window.h"
#include "./headers/situations.h"
#include "./headers/constants.h"
#include "./headers/particle.h"
#include "./headers/all_particles.h"
#include "./headers/all_squares.h"
#include "headers/square.h"

typedef int bool_t;

int		main (void) {
	bool_t			quit;
	SDL_Event		event;
	SDL_Window		*window;
	SDL_Texture		*text_texture;
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

	// FOR TESTS

	// situation3
		Particle particle_sit3 = init_particle(100.0f, 140.0f, 0.4f, 1.2f, 0.0000f, 0.0000f, 80.0f);
	// init only testing particles
		//init_all_particles();
	// init random count of particles with random values
		init_random_particles();
	// init only testing particles
		//Square *squares = init_all_squares();
	// init random count of particles with random values
		Square *squares = init_random_squares();


	print_squares();

	// END FOR TESTS

	quit = 0;
	int c = 0;
	while (!quit) {
		// if (c++ > 50)
		// 	dt = 400.0f;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = 1;
			}
		}

		SDL_SetRenderDrawColor(renderer, 11, 57, 84, 255);
		SDL_RenderClear(renderer);

		//situation0(renderer);
		//situation1(renderer);
		//situation2(renderer);
		//situation3(renderer, &particle_sit3);
		//situation4(renderer);
		//situation5(renderer);
		situation6(renderer, squares);

		SDL_RenderPresent(renderer);

		// approximately 60fps
		// 1000ms / 60 = 16.667 (dt is saved in constatns.h)
		// we want to have 60fps, so we need to calculate how fast should be one frame in 1second if we want
		// to have 60 frames in that second => 1s / 60frames = 0.016667s = 16.67ms
		SDL_Delay(dt);
	}
	return (0);
}