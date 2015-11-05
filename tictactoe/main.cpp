#include <iostream>
#include <vector>

// Model

enum class Mark { E=0, X=1, O=2 };

std::ostream & operator<<(std::ostream & out, Mark m) {
	switch (m) {
	case Mark::O:
		out << "O";
		break;
	case Mark::X:
		out << "X";
		break;
	default:
		out << ".";
	}
	return out;
}

class Board {
	std::vector<std::vector<Mark>> board;
public:
	Board(): board{{Mark::E, Mark::E, Mark::E}, {Mark::E, Mark::E, Mark::E}, {Mark::E, Mark::E, Mark::E}} { }
	bool set(int y, int x, Mark m) {
		if (board[y][x] == Mark::E) {
			board[y][x] = m;
			return true;
		}
		return false;
	}
	Mark win() {
		for (auto l : board) {
			if (l[0] == l[1] && l[1] == l[2]) {
				return l[0];
			}
		}
		for (size_t x=0; x < board[0].size(); x++) {
			if(board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
				return board[0][x];
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			return board[1][1];
		}
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
			return board[1][1];
		}
		return Mark::E;
	}
	void put(std::ostream & out) const {
		for (const auto & line: board) {
			for (auto elem: line) {
				out << elem;
			}
			out << std::endl;
		}
	}
};

std::ostream & operator<<(std::ostream & out, const Board & b) {
	b.put(out);
	return out;
}

// Logic
enum class State { MoveX=1, MoveO=2, WinX=3, WinO=4 };

class Logic {
	Board * board;
	State st;
public:
	Logic(Board * b): board(b), st(State::MoveX) { }
	const Board * getBoard() const {
		return board;
	}
	State state() const {
		return st;
	}
	void move(int y, int x) {
		if (board->set(y, x, (Mark)st)) {
			Mark win = board->win();
			if (win != Mark::E) {
				st = (win == Mark::X) ? State::WinX : State::WinO;
				return;
			}
			st = (st == State::MoveX) ? State::MoveO : State::MoveX;
		}
	}
};

// View

class View {
	Logic * logic;
public:
	View(Logic * l): logic(l) {}
	void Do() {
		int x, y;
		bool finished = false;
		while (!finished) {
			std::cout << std::endl << *(logic->getBoard()) << std::endl;
			switch (logic->state()) {
			case State::MoveX:
			case State::MoveO:
				std::cin >> x >> y;
				logic->move(y, x);
				break;
			case State::WinX:
				std::cout << "X wins!\n";
				finished = true;
				break;
			case State::WinO:
				std::cout << "O wins!\n";
				finished = true;
				break;
			}
		}
	}
};

// Starting point

int main() {
	Board b;
	Logic l(&b);
	View w(&l);
	w.Do();
}
