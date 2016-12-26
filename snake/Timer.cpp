#include "Timer.h"
#include <unistd.h>

void Timer::start() {
	while (true) {
		_game->update();
		_view->update();
		usleep(_freq * 1000);
		if (_game->state() != State::Cont) {
			break;
		}
	}
}
