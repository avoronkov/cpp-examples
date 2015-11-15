#include <iostream>
#include <string>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Abstract interface to get user's move
class UserInput {
public:
	virtual std::pair<int, int> getUserMove() = 0;
};

class Player {
	UserInput* ui;
public:
	Player() {}
	void setUserInput(UserInput * _ui) {
		ui = _ui;
	}
	string getState() const {
		return "Player moves";
	}
	std::pair<int, int> getMove() {
		// Get Input from user using some UI:
		return ui->getUserMove();
	}
};

class View : public UserInput {
	Player * player;
public:
	View(Player * p): player{p} {}
	void showState() {
		// Let's assume that game state is the only player state:
		cout << player->getState() << endl;
	}

	virtual std::pair<int, int> getUserMove() override {
		int x, y;
		cin >> x >> y;
		return std::pair<int, int>{x, y};
	}
};

int main() {
	Player player;
	View view{&player};
	player.setUserInput(&view);
	// auto user_move = player.getMove();
	view.showState();
}
