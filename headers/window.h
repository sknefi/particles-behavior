
# ifndef WINDOW_H
# define WINDOW_H

# include <SDL2/SDL.h>

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
SDL_Window		*create_window(const int x, const int y);
SDL_Renderer	*render_window(SDL_Window *window);

# endif //WINDOW_H
