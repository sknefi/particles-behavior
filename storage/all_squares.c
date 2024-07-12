#include <stdlib.h>
#include <time.h>
#include "../headers/square.h"
#include "../headers/window.h"

const int min_squares = 3;
const int max_squares = 6;
Square squares[max_squares];
int square_count;

Square	*init_all_squares() {
	squares[0] = init_square(150.0f, 740.0f, 0.0f, 0.0f, 40.0f);
	squares[1] = init_square(480.0f, 140.0f, 0.0f, 0.0f, 80.0f);
	squares[2] = init_square(220.0f, 210.0f, 0.0f, 0.0f, 100.0f);
	squares[3] = init_square(1000.0f, 850.0f, 0.0f, 0.0f, 20.0f);
	squares[4] = init_square(30.0f, 440.0f, 0.0f, 0.0f, 50.0f);
	squares[5] = init_square(-10105.0f, 0.0f, 0.0f, 0.0f, -10105.0f); // null-terminated

	return (squares);
}

Square	*init_random_squares() {
	srand(time(NULL));

	square_count = (rand() % (max_squares - min_squares)) + min_squares;

	int i = 0;
	while (i < square_count) {
		float x = (float)(rand() % WINDOW_WIDTH);
		float y = (float)(rand() % WINDOW_HEIGHT);
		float vx = 0;
		float vy = 0;
		float size = (float)(rand() % 100);

		squares[i] = init_square(x, y, vx, vy, size);
		i++;
	}
	squares[i] = init_square(-10105.0f, 0.0f, 0.0f, 0.0f, -10105.0f); // null-terminated
	return (squares);
}

int		is_null_term_square(Square square) {
	return ( (square.x == -10105.0f) && (square.size == -10105.0f) );
}

void	print_squares() {
	printf("Square count: %d\n", square_count);
	int i = 0;
	while (!is_null_term_square(squares[i])) {
		printf("Square %d: Position (%.2f, %.2f), Size: %.2f\n", i, squares[i].x, squares[i].y, squares[i].size);
		i++;
	}
}