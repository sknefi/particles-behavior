# ifndef ALL_SQUARES_H
# define ALL_SQUARES_H

# include "./square.h"

Square		*init_all_squares();
Square		*init_random_squares();
void		print_squares();
int			is_null_term_square(Square square);
void		draw_squares(SDL_Renderer *renderer, Square squares[]);

# endif //ALL_SQUARES_H
