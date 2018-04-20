#pragma once

#include "area.h"

class board {
private:
	area** tab;
	int tab_size;
	int mines_number;
	int mines_left;

public:
	explicit board(int, int);
	~board();
	
	friend std::ostream& operator<<(std::ostream&, const board&);

};