
# ifndef SQUARE_H
# define SQUARE_H

typedef struct {
	float				x;
	float				y;
	float				vx;
	float				vy;
	unsigned int		size;
} Square;

Square	init_square(float x, float y, float vx, float vy, unsigned int size);
void	draw_square_tl(SDL_Renderer *renderer, Square square);
void	draw_square_mid(SDL_Renderer *renderer, Square square);

# endif //SQUARE_H
