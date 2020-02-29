#pragma once
#include <iostream>

class Sea_Battle
{
private:
	unsigned int size;
	unsigned int count_ships;
	int** field;
public:
	Sea_Battle(int _size = 3)
	{
		count_ships = 0;
		size = _size;
		field = new int* [size];
		for (int k = 0; k < size; k++){
			field[k] = new int[size]();
		}
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size; j++)
				field[i][j] = 0;
		}
	}

	void Print_Field(int players_name = 1)
	{
		system("cls");
		std::cout << "  Player " << players_name << "." << std::endl;
		std::cout << std::endl;
		std::cout << "  ";
		for (int k = 0; k < size; k++) {
			std::cout << k << " ";
		}
		std::cout << std::endl;

		for (int i = 0; i < size; i++) {
			std::cout << i << " ";
			for (int j = 0; j < size; j++) {

				switch (field[i][j]) {
					case 0: {
						std::cout << " "; break;
					}
					case 1: {
						std::cout << "X "; break;
					}
					case -1: {
						std::cout << "O "; break;
					}
					case 2: {
						std::cout << "| "; break;
					}
				}
			}
			std::cout << std::endl;
		}
	}

	void Print_Help()
	{
		system("cls");
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				std::cout << "[" << i << "]" << "[" << j << "]" << " ";
			}
			std::cout << std::endl;
		}
	}

	void Strike(int x, int y)
	{
		if ((x >= 0) && (y >= 0) && (x <= size) && (y <= size)) {
			switch (field[x][y]) {
			case 2: {
				field[x][y] = 1;
				count_ships--;
				break;
			}
			case 1: {
				field[x][y] = 1;
				break;
			}
			case 0: {
				field[x][y] = -1;
				break;
			}
			case -1: {
				field[x][y] = -1;
				break;
			}
			}
		}
		else {
			std::cout << "Error!" << std::endl;
			std::cout << "X>0, Y>0, X<SIZE, Y<SIZE! Try again." << std::endl;
			system("pause");
		}
	}


	bool IsEmptyField()
	{
		if (count_ships == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Create_Ship(int x, int y) {
		if ((x >= 0) && (y >= 0) && (x <= size) && (y <= size)) {
			if (field[x][y] != 2) {
				field[x][y] = 2;
				count_ships++;
			}
		}
		else {
			std::cout << "Error!" << std::endl;
			std::cout << "X>0, Y>0, X<SIZE, Y<SIZE! Try again." << std::endl;
			system("pause");
		}
		
	}

	void Delete_Ship(int x, int y) {
		if ((x >= 0) && (y >= 0) && (x <= size) && (y <= size)) {
			if (field[x][y] == 0) {
				std::cout << "There's no ship. Error." << std::endl;
				system("pause");
			}
			else {
				field[x][y] = 0;
				if (count_ships > 0) {
					count_ships--;
				}
				else {
					std::cout << "Error! There's no ship." << std::endl;
				}
			}
		}
		else {
			std::cout << "Error!" << std::endl;
			std::cout << "X>0, Y>0, X<SIZE, Y<SIZE! Try again." << std::endl;
			system("pause");
		}
		
	}

	~Sea_Battle() 
	{
		delete[] field;
		count_ships = 0;
		size = 0;
	}

	Sea_Battle(const Sea_Battle& player)
	{
		count_ships = player.count_ships;
		size = player.size;
		field = new int* [size];
		for (int k = 0; k < size; k++) {
			field[k] = new int[size]();
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				field[i][j] = player.field[i][j];
		}
	}

	int Get_Count_Ships()
	{
		return count_ships;
	}

	void Admin_Print_Fields(const Sea_Battle& player)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "/*----------FIRST PLAYER----------*/";
		std::cout << std::endl;
		std::cout << "  ";
		for (int k = 0; k < size; k++) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << i << " ";
			for (int j = 0; j < size; j++) {
				/*switch (field[i][j]) {
					case 0: std::cout << "* ";
					case 1: std::cout << "X ";
					case -1: std::cout << "O ";
				}*/
				if (field[i][j] == 0) {
					std::cout << "  ";
				}
				/*else*/ if (field[i][j] == 1) {
					std::cout << "X ";
				}
				/*else*/ if (field[i][j] == -1) {
					std::cout << "O ";
				}
				/*else*/ if (field[i][j] == 2) {
					std::cout << "| ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "/*----------SECOND PLAYER----------*/";
		std::cout << std::endl;
		std::cout << "  ";
		for (int k = 0; k < player.size; k++) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < player.size; i++) {
			std::cout << i << " ";
			for (int j = 0; j < player.size; j++) {
				/*switch (field[i][j]) {
					case 0: std::cout << "* ";
					case 1: std::cout << "X ";
					case -1: std::cout << "O ";
				}*/
				if (player.field[i][j] == 0) {
					std::cout << "  ";
				}
				/*else*/ if (player.field[i][j] == 1) {
					std::cout << "X ";
				}
				/*else*/ if (player.field[i][j] == -1) {
					std::cout << "O ";
				}
				/*else*/ if (player.field[i][j] == 2) {
					std::cout << "| ";
				}
			}
			std::cout << std::endl;
		}
	}

	void Print_Battle(const Sea_Battle& player)
	{
		system("cls");
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "/*---------- [ FIRST PLAYER's FIELD ] ----------*/";
		std::cout << std::endl;
		std::cout << "  ";
		for (int k = 0; k < size; k++) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << i << " ";
			for (int j = 0; j < size; j++) {
				/*switch (field[i][j]) {
					case 0: std::cout << "* ";
					case 1: std::cout << "X ";
					case -1: std::cout << "O ";
				}*/
				if (field[i][j] == 0) {
					std::cout << "  ";
				}
				/*else*/ if (field[i][j] == 1) {
					std::cout << "X ";
				}
				/*else */if (field[i][j] == -1) {
					std::cout << "O ";
				}
				/*else*/ if (field[i][j] == 2) {
					std::cout << "| ";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "/*---------- [ SECOND PLAYER's FIELD ] ----------*/";
		std::cout << std::endl;
		std::cout << "  ";
		for (int k = 0; k < player.size; k++) {
			std::cout << k << " ";
		}
		std::cout << std::endl;
		for (int i = 0; i < player.size; i++) {
			std::cout << i << " ";
			for (int j = 0; j < player.size; j++) {
				/*switch (field[i][j]) {
					case 0: std::cout << "* ";
					case 1: std::cout << "X ";
					case -1: std::cout << "O ";
				}*/
				if (player.field[i][j] == 0) {
					std::cout << "  ";
				}
				/*else*/ if (player.field[i][j] == 1) {
					std::cout << "X ";
				}
				/*else*/ if (player.field[i][j] == -1) {
					std::cout << "O ";
				}
			}
			std::cout << std::endl;
		}
	}

	void Set_Random(int _max_count_ships=0)
	{
		int x, y;
		int tmp_x = -1;   //any nubmer < (min value of (field[x][y]>0))
		int tmp_y = -1;
			while (Get_Count_Ships() < _max_count_ships) {
				do {
					x = rand() % size;
					y = rand() % size;
				} while ((x == tmp_x) && (y == tmp_y));
				tmp_x = x;
				tmp_y = y;
				Create_Ship(x, y);
			}
	}


	

	




};

