#pragma once

#include <vector>
#include "area.h"
#include "Matrix.h"

class Board {
private:
	Matrix<area> tab;
	int tab_size;
	unsigned int mines_number;
	unsigned int mines_left;

public:
	Board(int, int);
	~Board();

	bool playing();
	bool uncover();
	void uncover_all();
	void flag();
	void if_0(int,int);

	friend std::ostream& operator<<(std::ostream&, Board&);

};
