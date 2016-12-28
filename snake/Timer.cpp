#include "Timer.h"
#include <unistd.h>

void Timer::start() {
	while (true) {
		_view->processControls();
		_game->update();
		_view->refreshScreen();
		usleep(_freq * 1000);
		if (_game->state() != State::Cont) {
			break;
		}
	}
}
