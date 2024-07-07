#include "../headers/all_particles.h"
#include "../headers/particle.h"

const int	count_of_particles = 4;
Particle	particles[count_of_particles];

void	init_all_particles() {
	particles[0] = init_particle(200.0f, 270.0f, 0.2f, 0.1f, 0.0000f, 0.0000f, 120.0f);
	particles[1] = init_particle(540.0f, 440.0f, 0.6f, 0.5f, 0.0000f, 0.0000f, 80.0f);
	particles[2] = init_particle(360.0f, 140.0f, 1.0f, 0.9f, 0.0000f, 0.0000f, 40.0f);
	particles[3] = init_particle(90.0f, 740.0f, 1.4f, 1.2f, 0.0000f, 0.0000f, 20.0f);
}

void	update_all_particles(SDL_Renderer *renderer, float dt) {
	int		i;

	i = 0;
	while (i < count_of_particles) {
		draw_particle(renderer, particles[i]);
		gravity_of_particle(&particles[i], dt);
		collision_wall_detection(&particles[i]);
		i++;
	}
}

