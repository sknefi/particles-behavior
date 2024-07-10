#include <stdlib.h>
#include <time.h>
#include "../headers/all_particles.h"
#include "../headers/particle.h"

const int min_particles = 5;
const int max_particles = 30;
Particle particles[max_particles];
int count_of_particles;

void	init_all_particles() {
	particles[0] = init_particle(200.0f, 270.0f, 0.2f, 0.1f, 0.0000f, 0.0000f, 120.0f);
	particles[1] = init_particle(540.0f, 440.0f, 0.6f, 0.5f, 0.0000f, 0.0000f, 80.0f);
	particles[2] = init_particle(360.0f, 140.0f, 1.0f, 0.9f, 0.0000f, 0.0000f, 40.0f);
	particles[3] = init_particle(90.0f, 740.0f, 1.4f, 1.2f, 0.0000f, 0.0000f, 20.0f);
	count_of_particles = 4;
}

void	init_random_particles() {
	int		i;

	srand(time(NULL));
	count_of_particles = rand() % (max_particles - min_particles + 1) + min_particles;
	i = 0;
	while (++i < count_of_particles) {
		float x = (float)(rand() % 600);  // Random x position within a range
		float y = (float)(rand() % 500);  // Random y position within a range
		float vx = ((float)(rand() % 200) - 100) / 100.0f;  // Random x velocity
		float vy = ((float)(rand() % 200) - 100) / 100.0f;  // Random y velocity
		float r = (float)(rand() % 50) + 10.0f;  // Random radius

		particles[i] = init_particle(x, y, vx, vy, 0.0f, 0.0f, r);
	}
}

// only wall collision
void	update_all_particles_sit4(SDL_Renderer *renderer, float dt) {
	int		i;

	i = 0;
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
	while (i < count_of_particles) {
		draw_particle(renderer, particles[i]);
		movement_of_particle(&particles[i], dt);
		collision_wall_detection(&particles[i]);
		collision_particle_detection(particles, count_of_particles);
		i++;
	}
}

// wall and particle detection
void	update_random_particles_sit6(SDL_Renderer *renderer, float dt) {
	int		i;

	i = 0;
	while (i < count_of_particles) {
		draw_particle(renderer, particles[i]);
		movement_of_particle(&particles[i], dt);
		collision_wall_detection(&particles[i]);
		collision_particle_detection(particles, count_of_particles);
		i++;
	}
}

