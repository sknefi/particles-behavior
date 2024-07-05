#include <SDL2/SDL.h>

#include "headers/particle.h"
#include "headers/square.h"

// testing particle
void	situation0(SDL_Renderer *renderer) {
	Particle		particle;

	particle = init_particle(100.0f, 100.0f, 0.0f, 0.0f, 10.0f);
	show_particle(particle);
}

// displaying squares
void	situation1(SDL_Renderer *renderer) {
	Square	square1;
	Square	square2;

	square1 = init_square(150.0f, 140.0f, 5.0f, 4.0f, 30);
	square2 = init_square(400.0f, 500.0f, 5.0f, 4.0f, 300);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	draw_square_mid(renderer, square1);
	draw_square_tl(renderer, square2);
}