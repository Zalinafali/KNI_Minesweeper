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
	bool czy_gramy();
	bool odkryj();
	void odkryj_wszystko();
	void flaga();
	friend std::ostream& operator<<(std::ostream&, board&);

};