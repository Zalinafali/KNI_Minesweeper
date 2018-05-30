#pragma once

#include <iostream>

class area {
private:
	bool mine;			// czy jest mina
	bool checked_area;	// czy pole zostalo odkryte
	bool flag;			// oflagowanie pola
	int mines_nearby;	// miny dotykajace obszaru

public:
	area();

	bool place_mine();
	bool checking_mine();

	int checking_mines_nearby();
	void add_mines_nearby();	// zwikszanie liczby sasiaduj¹cych min

	bool check_area();			// sprawdzenie danego obszaru
	bool checking_area();

	bool checking_flag();
	void change_flag();
	bool check_flag();

	friend std::ostream& operator<<(std::ostream&, const area&);
};