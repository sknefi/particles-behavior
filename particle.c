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

void	movement_of_particle(Particle *particle, const float dt) {
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

float	distance_between_two_particles(Particle particle1, Particle particle2) {
	float	dx = particle1.x - particle2.x;
	float	dy = particle1.y - particle2.y;

	return (sqrtf((dx * dx) + (dy * dy )));
}

float	skalar_product_of_vectors(float a, float b, float c, float d) {
	return ( (a * c) + (b * d));
}

// handle collision after touch of a two particles
void collision_particle_detection(Particle particles[], int count_of_particles) {
    int i;
    int j;
    float distance;

    i = 0;
    while (i < count_of_particles) {
        j = i + 1;
        while (j < count_of_particles) {
            // Distance between two particles
            distance = distance_between_two_particles(particles[i], particles[j]);
            // Collision of two particles
            if (distance <= (particles[i].r + particles[j].r)) {
                float	dx = particles[i].x - particles[j].x;
                float	dy = particles[i].y - particles[j].y;

                // Normal vector
                float	nx = dx / distance;
                float	ny = dy / distance;

                // Tangent vector
                float	tx = -ny;
                float	ty = nx;

                // Dot product tangent
                float	dpTan1 = particles[i].vx * tx + particles[i].vy * ty;
                float	dpTan2 = particles[j].vx * tx + particles[j].vy * ty;

                // Dot product normal
                float	dpNorm1 = particles[i].vx * nx + particles[i].vy * ny;
                float	dpNorm2 = particles[j].vx * nx + particles[j].vy * ny;

                // Conservation of momentum in 1D
                float	m1 = (dpNorm1 * (particles[i].r - particles[j].r) + 2.0f * particles[j].r * dpNorm2) / (particles[i].r + particles[j].r);
                float	m2 = (dpNorm2 * (particles[j].r - particles[i].r) + 2.0f * particles[i].r * dpNorm1) / (particles[i].r + particles[j].r);

                particles[i].vx = tx * dpTan1 + nx * m1;
                particles[i].vy = ty * dpTan1 + ny * m1;
                particles[j].vx = tx * dpTan2 + nx * m2;
                particles[j].vy = ty * dpTan2 + ny * m2;

                // Resolve overlap
                float overlap = 0.5f * (distance - particles[i].r - particles[j].r);
                particles[i].x -= overlap * nx;
                particles[i].y -= overlap * ny;
                particles[j].x += overlap * nx;
                particles[j].y += overlap * ny;
            }
            j++;
        }
        i++;
    }
}