#include "Board.h"

class Game {
private:
	int tab_size;
	int mines_number;

public:
	Game() : tab_size(0), mines_number(0) {}
	~Game() { std::cout << "Game destroyed!\n"; }

	void game_options();
	void play_game();

};
