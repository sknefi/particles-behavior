# ifndef SITUATIONS_H
# define SITUATIONS_H

#include <SDL2/SDL.h>
#include "./particle.h"
#include "./square.h"

void	situation0(SDL_Renderer *renderer);
void	situation1(SDL_Renderer *renderer);
void	situation2(SDL_Renderer *renderer);
void	situation3(SDL_Renderer *renderer, Particle *particle);
void	situation4(SDL_Renderer *renderer);
void	situation5(SDL_Renderer *renderer);
void	situation6(SDL_Renderer *renderer, Square squares[]);

# endif //SITUATIONS_H
