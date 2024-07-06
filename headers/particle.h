#ifndef PARTICLE_H
#define PARTICLE_H

typedef struct {
	float   x;
	float   y;
	float   vx;
	float   vy;
	float	ax;
	float	ay;
	float   r;
} Particle;

Particle	init_particle(float x, float y, float vx, float vy, float ax, float ay, float r);
void		show_particle(Particle particle);
void		draw_particle(SDL_Renderer *renderer, Particle particle);
void		gravity_of_circle(Particle *particle, const float dt);

#endif //PARTICLE_H
