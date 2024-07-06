#include <stdio.h>
#include <SDL2/SDL.h>
#include "./headers/window.h"

typedef struct {
	float   x;
	float   y;
	float   vx;
	float   vy;
	float	ax;
	float	ay;
	float   r;
} Particle;

Particle	init_particle(float x, float y, float vx, float vy, float ax, float ay, float r) {
	Particle	new_part;

	new_part.x = x;
	new_part.y = y;
	new_part.vx = vx;
	new_part.vy = vy;
	new_part.ax = ax;
	new_part.ay = ay;
	new_part.r = r;
	return (new_part);
}

void	show_particle(Particle particle) {
	printf("%p\n", &particle);
	printf("r:%f\n", particle.r);
	printf("x:%f\t\ty:%f\n", particle.x, particle.y);
	printf("vx:%f\t\t\tvy:%f\n", particle.vx, particle.vy);
	printf("vx:%f\t\t\tvy:%f\n", particle.ax, particle.ay);
	printf("------------------------------------------\n");
}

void	draw_particle(SDL_Renderer *renderer, Particle particle) {
	int			x = (particle.r - 1);
	int			y = 0;
	int			tx = 1;
	int			ty = 1;
	const int	diameter = (particle.r * 2);
	int			error = (tx - diameter);

	while (x >= y) {
		SDL_RenderDrawLine(renderer, particle.x - x, particle.y - y, particle.x + x, particle.y - y);
		SDL_RenderDrawLine(renderer, particle.x - x, particle.y + y, particle.x + x, particle.y + y);
		SDL_RenderDrawLine(renderer, particle.x - y, particle.y - x, particle.x + y, particle.y - x);
		SDL_RenderDrawLine(renderer, particle.x - y, particle.y + x, particle.x + y, particle.y + x);

		if (error <= 0) {
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0) {
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}

void	gravity_of_circle(Particle *particle, const float dt) {
	particle->vx = particle->vx + (particle->ax * dt);
	particle->vy = particle->vy + (particle->ay * dt);
	particle->x = particle->x + (particle->vx * dt);
	particle->y = particle->y + (particle->vy * dt);
}

void	collision_wall_detection(Particle *particle) {
	// collision with left or right wall (X-axis)
	if ((particle->x - particle->r < 0) || (particle->x + particle->r > WINDOW_WIDTH)) {
		particle->vx = -particle->vx;
	}
	if ((particle->y - particle->r < 0) || (particle->y + particle->r > WINDOW_HEIGHT)) {
		particle->vy = -particle->vy;
	}

}