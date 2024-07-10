# ifndef ALL_PARTICLES_H
# define ALL_PARTICLES_H

#include <SDL2/SDL.h>

void		init_all_particles();
void		init_random_particles();
void		update_all_particles_sit4(SDL_Renderer *renderer, float dt);
void		update_all_particles_sit5(SDL_Renderer *renderer, float dt);
void		update_random_particles_sit6(SDL_Renderer *renderer, float dt);

# endif //ALL_PARTICLES_H
