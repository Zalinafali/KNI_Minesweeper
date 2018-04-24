#pragma once

#include <vector>
#include "area.h"
#include "Matrix.h"

class board {
private:
	//area** tab;
	Matrix<area> tab;
	size_t tab_size;
	int mines_number;
	int mines_left;

public:
	explicit board(int, int);
	~board();
	
	friend std::ostream& operator<<(std::ostream&, board&);

};