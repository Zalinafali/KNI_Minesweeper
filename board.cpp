#include <iostream>
#include <ctime>
#include "board.h"
#include <random>
#include <cmath>

thread_local std::mt19937 gen{ std::random_device{}() };

template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

board::board(int _size, int _mines) : tab_size(_size), mines_number(_mines) {

	if (mines_number >= (tab_size-1) * (tab_size-1))		// max liczba min
		mines_number = (tab_size-1) * (tab_size-1);

	mines_left = mines_number;		// liczba pozosta³ych min

	tab = Matrix<area> (tab_size, tab_size);

	//std::cout << "Inicjalizacja tablicy.\n";
	//std::cout << "Tab size:\t" << tab_size << "\n";
	//std::cout << "Tab width:\t" << tab.width() << "\n";
	//std::cout << "Tab height:\t" << tab.height() << "\n";

	int mines_to_place = mines_number;		// losowe podk³adanie min
	int row, col,i,j,x,y,z;
	while (mines_to_place > 0) {

		row = random<int>(0, tab_size - 1);
		col = random<int>(0, tab_size - 1);

		if (tab(row, col).place_mine()) {		// jeœli nie ma miny, pod³ó¿ j¹
			mines_to_place--;
			//for (int i = 0; i < 3; i++)	// liczenie min w s¹siedzctwie
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
		}
	}
	std::cout << "Usatwienie i zliczenie min.\n";
}

board::~board() {
	/*for (int i = 0; i < tab_size*tab_size; i++)
		delete &(tab(0,i));*/
	std::cout << "Board destroyed!\n";
}

bool board::playing()
{
	int a = 0;
	for (int i = 0; i < tab.width(); i++)
		for (int j = 0; j < tab.height(); j++) {
			if(tab(i, j).checking_area())a++;		// najpierw trzeba odkryæ wszystkie
		}
	a=(tab_size*tab_size) - a;
	if (a==mines_number)return false;
	else return true;
}

int my_MAX(int a, int b) {
	return (a + b + abs(a - b)) / 2;
}

bool board::uncover()
{
	int row, col,ver,hor,vof,hof;
	int loop_row,loop_col,loop,i,j,k;
	std::cout << "Podaj (wiersz kolumne):\n";
	std::cin >> row;
	std::cin >> col; 
	std::cin.clear();
	if (row > tab.height() || col > tab.width()|| row-1 <0 || col-1 <0)return false;
	if (tab(row - 1, col - 1).checking_flag()) return false;
	if (tab(row - 1, col - 1).checking_area()) return false;
	if (!tab(row-1, col-1).checking_mine()) {		// <-- tu stawia³eœ minê przy odkrywaniu, check_area() odkrywa pole jeœli nie by³o odkryte
		if (tab(row - 1, col - 1).checking_mines_nearby() == 0) if_0(row - 1, col - 1);
		else tab(row - 1, col - 1).check_area();
		return false;
	}
	return true;
}

void board::uncover_all()
{
	for(int i = 0; i < tab.width(); i++)
		for (int j = 0; j < tab.height(); j++) {
			tab(i, j).check_area();		// najpierw trzeba odkryæ wszystkie
		}								// potem mo¿na wypisaæ wszystko
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

void board::if_0(int row, int col)
{
	if (row  > tab.height()-1 || col > tab.width()-1 || row < 0 || col < 0)return;
	if (!tab(row , col ).checking_area())
		tab(row , col).check_area();
	else return;
	if (tab(row, col).checking_mines_nearby())return;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if_0(row - 1 + i, col - 1 + j);
		}
	}
	return;
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