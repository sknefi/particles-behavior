#include <stdlib.h>
#include <time.h>
#include "../headers/all_particles.h"
#include "../headers/particle.h"
#include "../headers/all_squares.h"
#include "../headers/square.h"

const int min_particles = 2;
const int max_particles = 5;
Particle particles[max_particles];
int count_of_particles = 6;

void	init_all_particles() {
	particles[0] = init_particle(200.0f, 270.0f, 0.2f, 0.1f, 0.0000f, 0.0000f, 120.0f);
	//particles[5] = init_particle(150.0f, 640.0f, 0.4f, 0.2f, 0.0000f, 0.0000f, 100.0f);
	particles[1] = init_particle(540.0f, 440.0f, 0.6f, 0.5f, 0.0000f, 0.0000f, 80.0f);
	//particles[4] = init_particle(200.0f, 440.0f, 0.8f, 0.7f, 0.0000f, 0.0000f, 60.0f);
	particles[2] = init_particle(360.0f, 140.0f, 1.0f, 0.9f, 0.0000f, 0.0000f, 40.0f);
	particles[3] = init_particle(90.0f, 640.0f, 1.4f, 1.2f, 0.0000f, 0.0000f, 20.0f);
}

void	init_random_particles() {
	int		i;

	srand(time(NULL));
	count_of_particles = rand() % (max_particles - min_particles + 1) + min_particles;
	i = 0;
	while (++i < count_of_particles) {
		float x = (float)(rand() % 500);  // Random x position within a range
		float y = (float)(rand() % 600);  // Random y position within a range
		float vx = ((float)(rand() % 200) - 100) / 100.0f;  // Random x velocity
		float vy = ((float)(rand() % 200) - 100) / 100.0f;  // Random y velocity
		float r = (float)(rand() % 70) + 10.0f;  // Random radius

		particles[i] = init_particle(x, y, vx, vy, 0.0f, 0.0f, r);
	}
}

// only wall collision
void	update_all_particles_sit4(SDL_Renderer *renderer, float dt) {
	int		i;

	i = 0;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	while (i < count_of_particles) {
		draw_particle(renderer, particles[i]);
		movement_of_particle(&particles[i], dt);
		collision_wall_detection(&particles[i]);
		i++;

		SDL_Delay(dt);
	}
}

// wall and particle detection
void	update_all_particles_sit5(SDL_Renderer *renderer, float dt) {
	int		i;

	i = 0;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	while (i < count_of_particles) {
		draw_particle(renderer, particles[i]);
		movement_of_particle(&particles[i], dt);
		collision_wall_detection(&particles[i]);
		collision_particles_detection(particles, count_of_particles);
		i++;
	}
}

// square and particle detection
void	update_all_particles_sit6(SDL_Renderer *renderer, Square squares[], float dt) {
	int		i;

	i = 0;
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	while (i < count_of_particles) {
		draw_particle(renderer, particles[i]);
		movement_of_particle(&particles[i], dt);
		collision_wall_detection(&particles[i]);
		collision_particles_detection(particles, count_of_particles);
		collision_square_detection(&particles[i], squares);
		i++;
	}
}


