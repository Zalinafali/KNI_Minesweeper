#pragma once

#include <iostream>

class area {
private:
	bool mine;			// czy jest mina
	bool checked_area;	// czy pole zosta³o sprawdzone
	bool flag;			// oflagowanie pola
	bool is_active;		// czy styka siê z ods³oniêtym polem
	int mines_nearby;	// miny dotykaj¹ce obszaru

public:
	area();

	bool place_mine();
	bool check_area();			// sprawdzenie danego obszaru
	void change_flag();

	void add_mines_nearby();	// liczba s¹siaduj¹cych min

	friend std::ostream& operator<<(std::ostream&, const area&);
};