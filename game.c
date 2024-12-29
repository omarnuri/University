#include<stdio.h>
#include<locale.h>
#pragma region Goals
//create map 7x7
//declare players p1 red, p2 yellow, p3 blue
//locate players in the center of the board, diagonally, horizontally or vertically to each other on board
//write game logic
#pragma endregion
//1 - format error, 2 - coordinats error

#define MAX_CAP 23
#define ERROR_FORMATING (1<<0)
#define ERROR_OUT_OF_RANGE (1<<1)
#define ERROR_FILLED_FIELD (1<<2)



int main() {
	setlocale(LC_ALL, "Russian");

	int i = 0, j = 0;
	int map[MAX_CAP][MAX_CAP] = {0};
	int map_hor_len = 7, map_ver_len = 7;
	int player_1 = 1;
	int player_2 = 2;
	int player_3 = 3;
	int empty_block = 0;



	

#pragma region LocatePlayers
	int center_x = map_hor_len / 2;
	int center_y = map_ver_len / 2;

	if (center_x+1 < map_hor_len && center_x-1 >= 0)
	{
		map[center_y][center_x] = player_1;
		map[center_y][center_x-1] = player_2;
		map[center_y][center_x+1] = player_3;

	}


#pragma endregion

#pragma region GameLogic
	int fields_filled = 3;
	int player_1_filled = 1, player_2_filled = 1, player_3_filled = 1;
	int fields_max = map_hor_len * map_ver_len;
	int sel_x = 0, sel_y = 0;
	int player_turn = 1;
	unsigned short error_flags = 0;
	while (fields_filled != fields_max) {
		//print
#pragma region DrawMap
	    printf("  ");
		for (j = 0; j < map_hor_len; j++)
		{
			printf("%d ", j+1);
		}
		printf("\n");
		for (i = 0; i < map_ver_len; i++) {
			printf("%d ", i + 1);
			for (j = 0; j < map_hor_len; j++)
			{
				if (map[i][j] == empty_block)
				{
					printf("* ");
				}
				else if (map[i][j] == player_1) {
					printf("K ");
				}
				else if (map[i][j] == player_2) {
					printf("S ");
				}
				else if (map[i][j] == player_3) {
					printf("M ");
				}

			}
			printf("\n");
		}
#pragma endregion


		//input/input_check
		int isChecked = 0;
		while (error_flags!=0 || isChecked!=1)
		{
			if (error_flags & ERROR_FORMATING)
			{
				printf("ERROR: wrong formating, pls input coordinates in (x/y) format\n");
				error_flags &= ~ERROR_FORMATING;
			}
			if (error_flags & ERROR_OUT_OF_RANGE)
			{
				printf("ERROR: Your input is out of range, pls choose number between (1-7)\n");
				error_flags &= ~ERROR_OUT_OF_RANGE;
			}
			if (error_flags & ERROR_FILLED_FIELD)
			{
				printf("ERROR: This field is allready filled, pls choose empty field\n");
				error_flags &= ~ERROR_FILLED_FIELD;
			}
			printf("player_%d input coordinats(x/y): ", player_turn);
			int suc_form = scanf("%d/%d", &sel_x, &sel_y);
			sel_x--;
			sel_y--;
			if (suc_form != 2)
			{
				error_flags |= ERROR_FORMATING;
			}
			if (sel_x<0 || sel_x>= map_hor_len || sel_y < 0 || sel_y>=map_ver_len)
			{
				error_flags |= ERROR_OUT_OF_RANGE;
			
			}
			else if (map[sel_y][sel_x])
			{
				error_flags |= ERROR_FILLED_FIELD;
			}
			isChecked = 1;
		}
		
		
		//calculate/setup

		map[sel_y] [sel_x] = player_turn;
		//ЗДЕСЬ ДОБАВЬ ПРОВЕРКУ НА ХОД
		player_turn = (player_turn % 3) + 1;
		system("cls");
	
	}


#pragma endregion 



}