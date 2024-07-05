#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct {
	float   x;
	float   y;
	float   vx;
	float   vy;
	float   r;
} Particle;

Particle	init_particle(float x, float y, float vx, float vy, float r) {
	Particle	new_part;

	new_part.x = x;
	new_part.y = y;
	new_part.vx = vx;
	new_part.vy = vy;
	new_part.r = r;
	return (new_part);
}

void	show_particle(Particle particle) {
	printf("%p\n", &particle);
	printf("r:%f\n", particle.r);
	printf("x:%f\t\ty:%f\n", particle.x, particle.y);
	printf("vx:%f\t\t\tvy:%f\n", particle.vx, particle.vy);
	printf("------------------------------------------\n");
}
