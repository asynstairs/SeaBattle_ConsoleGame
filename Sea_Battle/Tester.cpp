#include "Sea_Battle.h"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <Windows.h>
using namespace std;

int main()
{
start_goto:

	system("color F0");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	char edit_question, create_delete_question, random_question, admin_question;
	bool two_players_mode;
	unsigned int x, y, localsize, max_count_ship;

	/*------------------- WELCOME SCREEN -------------------*/

	cout << "/*---------------------*/" << endl;
	cout << "  Welcome to Sea Battle!" << endl;
	cout << "/*---------------------*/" << endl;
		cout << endl;
			cout << "[ Settings ]" << endl;
			cout << "Size of fields: ";
				cin >> localsize;

			cout << "Max count of ships that may be created: ";
				cin >> max_count_ship;

		if (max_count_ship > (localsize * localsize)) {
			cout << "Max count of ships < (size*size)! Error." << endl;
				system("pause");
				system("cls");
					goto start_goto;
		}

	cout << "Play with Bot (0) or with Player (1)? (0/1):  ";
		cin >> two_players_mode;

	cout << "Admin mode ON? (y/n): ";
		cin >> admin_question;

play_again_goto:

	Sea_Battle Player1(localsize);
	Sea_Battle Player2(localsize);

	/*---------------------------- FIRST PLAYER SETTINGS  -----------------------------------*/

	while (Player1.Get_Count_Ships() < max_count_ship) {
		cout << "Set random your ships? (y/n): " << endl;
			cin >> random_question;

				if ((random_question == 'y') || (random_question == 'Y')) {
					cout << "Randomizing your ships location..." << endl;
						Player1.Set_Random(max_count_ship);
						Player1.Print_Field();
				}
				else {
						Player1.Print_Field(1);
						cout << endl;
						cout << "X,Y: ";
							cin >> x >> y;
								Player1.Create_Ship(x, y);
				}
	}

	Player1.Print_Field(1);
		cout << endl;

	cout << "Player 1! Do you want to EDIT your field? y/n: ";
		cin >> edit_question;

	if ((edit_question == 'y') || (edit_question == 'Y')) {
		cout << "!!! To close editing write 'e'" << endl; 
			while ((create_delete_question != 'e') && (create_delete_question != 'E')) {
				cout << "Create (c) or delete (d) a ship? c/d: ";
					cin >> create_delete_question;

						if ((create_delete_question == 'c') || (create_delete_question == 'C')) {
							cout << endl;
							cout << "[CREATE A SHIP]: X,Y: ";
								cin >> x >> y;

								if (Player1.Get_Count_Ships() != max_count_ship) {
									Player1.Create_Ship(x, y);
									Player1.Print_Field(1);
								}
								else {
										cout << "Error! Max count of ships." << endl;
										cout << "Delete a ship to create new one." << endl;
								}
						}
						else {
							if ((create_delete_question == 'd') || (create_delete_question == 'D')) {
								cout << endl;
								cout << "[DELETE A SHIP]: X,Y: ";
									cin >> x >> y;
									Player1.Delete_Ship(x, y);
									Player1.Print_Field(1);
							}
					
						}
			}
	}

	srand(time(NULL));
	/*----------------------------SECOND PLAYER SETTINGS -----------------------------------*/
	int tmp_x = -1;
	int tmp_y = -1;
	int x_p2, y_p2;

	while (Player2.Get_Count_Ships() < max_count_ship) {
		if (two_players_mode) {
			Player2.Print_Field(2);
				cout << endl;
				cout << "X,Y: ";
					cin >> x >> y;
						Player2.Create_Ship(x, y);
		}
		else {
			do {
				x_p2 = rand() % localsize;
				y_p2 = rand() % localsize;
			} while ((x_p2 == tmp_x) && (y_p2 == tmp_y));
				tmp_x = x_p2;
				tmp_y = y_p2;
					Player2.Create_Ship(x_p2, y_p2);
		}
	}

	Player2.Print_Field(2);
		cout << endl;

	if (two_players_mode) {
		cout << "Player 2! Do you want to EDIT your field? y/n: ";
			cin >> edit_question;

			if ((edit_question == 'y') || (edit_question == 'Y')) {
				cout << "!!! To close editing write 'e'" << endl; 

					while ((create_delete_question != 'e') && (create_delete_question != 'E')) {
						cout << "Create (c) or delete (d) a ship? c/d: ";
							cin >> create_delete_question;

								if ((create_delete_question == 'c') || (create_delete_question == 'C')) {
									cout << endl;
									cout << "[CREATE A SHIP]: X,Y: ";
										cin >> x >> y;

									if (Player2.Get_Count_Ships() != max_count_ship) {
										Player2.Create_Ship(x, y);
										Player2.Print_Field(2);
									}
									else {
											cout << "Error! Max count of ships." << endl;
											cout << "Delete a ship to create new one." << endl;
									}
								}
								else {
									if ((create_delete_question == 'd') || (create_delete_question == 'D')) {
										cout << endl;
										cout << "[DELETE A SHIP]: X,Y: ";
											cin >> x >> y;

												Player2.Delete_Ship(x, y);
												Player2.Print_Field(2);
									}
								}
					}
			}
	}

	cout << endl;
		cout << "GAME HAS STARTED!" << endl;
			cout << endl;

	int player1_count_ships = Player1.Get_Count_Ships();
	int player2_count_ships = Player2.Get_Count_Ships();

	/*----------------------- FIRST PLAYER'S GAMEPLAY -----------------------*/
	
	while (!(Player1.IsEmptyField()) && (!Player2.IsEmptyField())) {
		Player1.Print_Battle(Player2);
			cout << endl;
		do {
			cout << "- [ FIRST PLAYER ] -> X,Y:  ";
				cin >> x >> y;
					player2_count_ships = Player2.Get_Count_Ships();
						Player2.Strike(x, y);
						if ((admin_question == 'y')||(admin_question == 'Y')) {
							Player1.Admin_Print_Fields(Player2);
						}
						else {
							Player1.Print_Battle(Player2);
						}

		} while ((Player2.Get_Count_Ships() < player2_count_ships)&&
				(!(Player1.IsEmptyField())&&
				(!Player2.IsEmptyField())));
					
		if ((admin_question == 'y') || (admin_question == 'Y')) {
			Player1.Admin_Print_Fields(Player2);
		}
		else {
			Player1.Print_Battle(Player2);
		}
		system("pause");
		system("cls");

		/*----------------------- SECOND PLAYER's GAMEPLAY -----------------------*/

		int tmp_x = -1;
		int tmp_y = -1;
		x = rand() % localsize;
		y = rand() % localsize;

		if (!(Player1.IsEmptyField()) && (!Player2.IsEmptyField())) {
				Player2.Print_Battle(Player1);
					if (two_players_mode) {
						do {
							cout << "- [ SECOND PLAYER ] -> X,Y: ";
								cin >> x >> y;
									player2_count_ships = Player1.Get_Count_Ships();
										Player1.Strike(x, y);
										Player2.Print_Battle(Player1);

						} while ((Player1.Get_Count_Ships() < player2_count_ships)&&
								(!(Player1.IsEmptyField())&&
								(!Player2.IsEmptyField())));

								system("pause");
					}
			/*----------------------- BOT's GAMEPLAY -----------------------*/
					else {
						do {
							do {
								x = rand() % localsize;
								y = rand() % localsize;
							} while ((tmp_x == x) && (tmp_y == y));

							player1_count_ships = Player1.Get_Count_Ships();
								tmp_x = x;
								tmp_y = y;
									Player1.Strike(x, y);
												Player1.Print_Battle(1);
					
						} while ((Player1.Get_Count_Ships() < player1_count_ships)&&
								(!(Player1.IsEmptyField())&&
								(!Player2.IsEmptyField())));
					}
				}
			
		}
	

	system("cls");

	/*----------------------- RESULTS -----------------------*/

	cout << "/*------ [ GAME OVER ] -----*/" << endl;

	Player1.Admin_Print_Fields(Player2);	
		cout << endl;

	if (Player1.IsEmptyField() == false) {
		cout << "/*----- [ First player wins! ] -----" << endl;
	}
	else {
		if (Player2.IsEmptyField() == false) {
			cout << "----- [ Second player wins! ] -----" << endl;
		}
		else {
			cout << "----- [ Draw! ] -----" << endl;
		}
	}
	
		system("pause");
		system("cls");
			cout << endl;
			cout << "Play again? y/n: ";
				char play_again_question;
					cin >> play_again_question;
						if ((play_again_question == 'y') || (play_again_question == 'Y')) {
							goto play_again_goto;
						}
	system("pause");
		return 0;
}