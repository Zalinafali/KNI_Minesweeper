#pragma once

#include <iostream>

class area {
private:
	bool mine;
	bool show_area;
	bool flag;
	bool is_active;		// czy styka si� z ods�oni�tym polem
	int mines_nearby;	// miny dotykaj�ce obszaru

public:
	area();

	bool place_mine();
	bool check_area();			// sprawdzenie danego obszaru
	void change_flag();

	void add_mines_nearby();	// liczba s�siaduj�cych min

	friend std::ostream& operator<<(std::ostream&, const area&);
};