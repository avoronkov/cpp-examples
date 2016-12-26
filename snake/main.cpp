#include "Snake.h"
#include "View.h"
#include "Timer.h"

int main() {
	View view;
	int width = view.screenWidth();
	int height = view.screenHeight();
	Field field{width, height};
	Snake snake{width/2, height/2};
	Game game{&field, &snake};
	view.setGame(&game);

	Timer timer{&game, &view};
	timer.start();

	return 0;
}
