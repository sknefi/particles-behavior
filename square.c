#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct {
	float				x;
	float				y;
	unsigned int		size;
} Square;

Square	init_square(float x, float y, unsigned int size) {
	Square square;

	square.x = x;
	square.y = y;
	square.size = size;
	return  (square);
}

void	draw_square_tl(SDL_Renderer *renderer, Square square) {
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < square.size) {
		j = 0;
		while (j < square.size) {
			SDL_RenderDrawPoint(renderer, square.x + i, square.y + j);
			j++;
		}
		i++;
	}
}

void	draw_square_mid(SDL_Renderer *renderer, Square square) {
	int		i;
	int		j;

	i = 0;
	while (i < square.size) {
		j = 0;
		while (j < square.size) {
			SDL_RenderDrawPoint(renderer, square.x - (square.size / 2) + i, square.y - (square.size / 2) + j);
			j++;
		}
		i++;
	}
}

void	show_square(Square square) {
	printf("%p\n", &square);
	printf("%u\n", square.size);
	printf("x:%f\t\ty:%f\n", square.x, square.y);
	printf("------------------------------------------\n");
}