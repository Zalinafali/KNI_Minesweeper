#include <iostream>
#include <ctime>
#include "board.h"

board::board(int _size, int _mines) : tab_size(_size), mines_number(_mines), tab(Matrix<area>(tab_size, tab_size)) {
	srand(time(NULL));

	if (mines_number >= (tab_size-1) * (tab_size-1))		// max liczba min
		mines_number = (tab_size-1) * (tab_size-1);

	mines_left = mines_number;		// liczba pozosta³ych min

	//tab = new (std::nothrow) area*[tab_size];		// inicjalizacja tabilcy
	//for (int i = 0; i < tab_size; i++)
	//	tab[i] = new (std::nothrow) area[tab_size];

	std::cout << "Inicjalizacja tablicy.\n";

	int mines_to_place = mines_number;		// losowe podk³adanie min
	int row, col;
	while (mines_to_place > 0) {
		row = rand() % tab_size;
		col = rand() % tab_size;

		if (tab(row, col).place_mine()) {		// jeœli nie ma miny, pod³ó¿ j¹
			mines_to_place--;
			//for (int i = 0; i < 3; i++)	// liczenie min w s¹siedzctwie
			//	if (row - 1 + i >= 0 && row - 1 + i < tab_size && col - 1 + i >= 0 && col - 1 + i < tab_size)
			//		tab(row - 1 + i, col - 1 + i).add_mines_nearby();
		
			
		
		}
	}
	std::cout << "Usatwienie i zliczenie min.\n";
}

board::~board() {
	/*for (int i = 0; i < tab_size; i++)
		delete[] tab[i];
	delete[] tab;*/
	std::cout << "Board destroyed!\n";
}



std::ostream& operator<<(std::ostream& out, board& source) {
	out << "  ";
	for (int i = 0; i < source.tab_size; i++)
		out << i + 1 << " ";
	out << "\n";
	for (int i = 0; i < source.tab_size; i++) {
		out << i + 1 << " ";
		for (int j = 0; j < source.tab_size; j++)
			out << source.tab(i, j) << " ";
		out << "\n";
	}
	return out;
}