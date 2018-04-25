#include <iostream>
#include <ctime>
#include "board.h"
#include <random>

thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

board::board(int _size, int _mines) : tab_size(_size), mines_number(_mines) {

	if (mines_number >= (tab_size-1) * (tab_size-1))		// max liczba min
		mines_number = (tab_size-1) * (tab_size-1);

	mines_left = mines_number;		// liczba pozosta�ych min

	tab = Matrix<area> (tab_size, tab_size);

	//std::cout << "Inicjalizacja tablicy.\n";
	//std::cout << "Tab size:\t" << tab_size << "\n";
	//std::cout << "Tab width:\t" << tab.width() << "\n";
	//std::cout << "Tab height:\t" << tab.height() << "\n";

	int mines_to_place = mines_number;		// losowe podk�adanie min
	int row, col,i,j,x,y,z;
	while (mines_to_place > 0) {

		row = random<int>(0, tab_size - 1);
		col = random<int>(0, tab_size - 1);

		if (tab(row, col).place_mine()) {		// je�li nie ma miny, pod�� j�
			mines_to_place--;
			//for (int i = 0; i < 3; i++)	// liczenie min w s�siedzctwie
			//	if (row - 1 + i >= 0 && row - 1 + i < tab_size && col - 1 + i >= 0 && col - 1 + i < tab_size)
			//		tab(row - 1 + i, col - 1 + i).add_mines_nearby();
			//if (row > 0 && row + 1 < tab_size && col > 0 && col + 1 < tab_size) { i = 0; j = 0; }
			if (row > 0) { i = 0; }
			else { i = 1; }
			if (row  < tab_size-1) { x=3; }
			else { x=2; }
			if (col > 0) { j = 0; }
			else { j = 1; }
			if (col < tab_size-1) { y = 3; }
			else { y = 2; }
			z = j;
			for (; i < x; i++) {
				for (j=z; j < y; j++) {
					tab(row - 1 + i, col - 1 + j).add_mines_nearby();
				}
			}
			/*std::cout << *this;
			system("PAUSE");*/
		}
	}
	/*for (int i = 0; i < tab.width(); i++)
		for (int j = 0; j < tab.height(); j++) {
			if(tab(i,j).)
		}*/
	std::cout << "Usatwienie i zliczenie min.\n";
}

board::~board() {
	/*for (int i = 0; i < tab_size*tab_size; i++)
		delete &(tab(0,i));*/
	std::cout << "Board destroyed!\n";
}

bool board::playing()
{
	std::cout << mines_left <<std::endl;
	system("PAUSE");
	if (mines_left)return true;
	return false;
}

bool board::uncover()
{
	int row, col;
	std::cout << "Podaj wiersz:\n";
	std::cin >> row;
	std::cout << "Podaj kolumne:\n";
	std::cin >> col;
	if (row > tab.height() || col > tab.width())return false;
	if (tab(row - 1, col - 1).check_flag()) return false;
	//if (!tab(wiersz-1, kolumna-1).check_area()) {		// <-- tu stawia�e� min� przy odkrywaniu, check_area() odkrywa pole je�li nie by�o odkryte

	//}
	return true;

}

void board::uncover_all()
{
	for(int i = 0; i < tab.width(); i++)
		for (int j = 0; j < tab.height(); j++) {
			tab(i, j).check_area();		// najpierw trzeba odkry� wszystkie
		}								// potem mo�na wypisa� wszystko
	//std::cout << (*this);

	/*for (int i = 0; i < tab.width() ;i++) {
		for (int j = 0; j < tab.height();j++) {
			tab(i, j).check_area();
		}
	}*/
}

void board::flag()
{
	int wiersz, kolumna;
	std::cout << "Podaj wiersz:\n";
	std::cin >> wiersz;
	std::cout << "Podaj kolumne:\n";
	std::cin >> kolumna;
	if (wiersz > tab.height() || kolumna > tab.width())return;
	else tab(wiersz-1, kolumna-1).change_flag();
}



std::ostream& operator<<(std::ostream& out, board& source) {
	out << "	";
	for (int i = 0; i < source.tab_size; i++)
		out << i + 1 << " ";
	out << "\n";
	for (int i = 0; i < source.tab_size; i++) {
		out << i + 1 << "	";
		for (int j = 0; j < source.tab_size; j++)
			out << source.tab(i, j) << " ";
		out << "\n";
	}
	return out;
}