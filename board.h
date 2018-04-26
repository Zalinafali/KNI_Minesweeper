#pragma once

#include <vector>
#include "area.h"
#include "Matrix.h"

class board {
private:
	//area** tab;
	Matrix<area> tab;
	size_t tab_size;
	unsigned int mines_number;
	unsigned int mines_left;

public:
	explicit board(int, int);
	~board();
	bool playing();
	bool uncover();
	void uncover_all();
	void flag();
	void if_0(int,int);
	friend std::ostream& operator<<(std::ostream&, board&);

};
