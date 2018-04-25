#pragma once

#include <iostream>

class area {
private:
	bool mine;			// czy jest mina
	bool checked_area;	// czy pole zosta�o odkryte
	bool flag;			// oflagowanie pola
	bool is_active;		// czy styka si� z odkrytym polem
	int mines_nearby;	// miny dotykaj�ce obszaru

public:
	area();

	bool place_mine();
	bool check_area();			// sprawdzenie danego obszaru
	bool check_mine();
	void change_flag();
	bool check_flag();

	void add_mines_nearby();	// liczba s�siaduj�cych min

	friend std::ostream& operator<<(std::ostream&, const area&);
};