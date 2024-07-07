# ifndef PARTICLE_H
# define PARTICLE_H

#include <SDL2/SDL.h> // Make sure to include SDL.h if you're using SDL functions and types

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
void		gravity_of_particle(Particle *particle, const float dt);
void		collision_wall_detection(Particle *particle);

#endif //PARTICLE_H
