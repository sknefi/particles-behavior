#include <stdio.h>
#include <SDL2/SDL.h>

#include "./headers/particle.h"
#include "./headers/window.h"

int	main (void) {
	int				quit;

	Particle		particle;
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
	particle = init_part(100.0f, 100.0f, 0.0f, 0.0f, 10.0f);
	show_particle(particle);

	return (0);
}