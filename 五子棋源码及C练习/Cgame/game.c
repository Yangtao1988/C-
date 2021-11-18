#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define ROWS 9
#define COLS 9

char board[ROWS][COLS];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);
void startGame();
int main()
{
	system("color 02");
	startGame();
	
	return 0;
}

void startGame()
{
	char winner = ' ';
	char response = 'Y';
	
	 while(response == 'Y')
	 {
		winner = ' ';
		response = ' ';
		
		resetBoard();
		while (winner == ' ' && checkFreeSpaces() != 0)
		{
			system("cls");
			printBoard();
			playerMove();
			winner = checkWinner();
			if (winner != ' ' && checkFreeSpaces() == 0)
			{
				break;
			}
			computerMove();
			winner = checkWinner();
			if (winner != ' ' && checkFreeSpaces() == 0)
			{
				break;
			}
		}
		printBoard();
		printWinner(winner);
		
		fflush(stdin);
		printf("Would you like play again?(Y/N):");
		scanf("%c", &response);
		response = toupper(response);
	}

	printf("Thanks for playing");
	system("pause");
}


void resetBoard()
{
	for (unsigned int i = 0; i < ROWS; i++)
	{
		for (unsigned int j = 0; j < COLS; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void printBoard()
{
	printf("\n-|-1-|-2-|-3-|-4-|-5-|-6-|-7-|-8-|-9-|-\n");
	printf("1| %c | %c | %c | %c | %c | %c | %c | %c | %c |1", board[0][0], board[0][1], board[0][2],board[0][3], board[0][4], board[0][5],board[0][6], board[0][7], board[0][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("2| %c | %c | %c | %c | %c | %c | %c | %c | %c |2", board[1][0], board[1][1], board[1][2],board[1][3], board[1][4], board[1][5],board[1][6], board[1][7], board[1][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("3| %c | %c | %c | %c | %c | %c | %c | %c | %c |3", board[2][0], board[2][1], board[2][2],board[2][3], board[2][4], board[2][5],board[2][6], board[2][7], board[2][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("4| %c | %c | %c | %c | %c | %c | %c | %c | %c |4", board[3][0], board[3][1], board[3][2],board[3][3], board[3][4], board[3][5],board[3][6], board[3][7], board[3][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("5| %c | %c | %c | %c | %c | %c | %c | %c | %c |5", board[4][0], board[4][1], board[4][2],board[4][3], board[4][4], board[4][5],board[4][6], board[4][7], board[4][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("6| %c | %c | %c | %c | %c | %c | %c | %c | %c |6", board[5][0], board[5][1], board[5][2],board[5][3], board[5][4], board[5][5],board[5][6], board[5][7], board[5][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("7| %c | %c | %c | %c | %c | %c | %c | %c | %c |7", board[6][0], board[6][1], board[6][2],board[6][3], board[6][4], board[6][5],board[6][6], board[6][7], board[6][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("8| %c | %c | %c | %c | %c | %c | %c | %c | %c |8", board[7][0], board[7][1], board[7][2],board[7][3], board[7][4], board[7][5],board[7][6], board[7][7], board[7][8]);
	printf("\n-|---|---|---|---|---|---|---|---|---|-\n");
	printf("9| %c | %c | %c | %c | %c | %c | %c | %c | %c |9", board[8][0], board[8][1], board[8][2],board[8][3], board[8][4], board[8][5],board[8][6], board[8][7], board[8][8]);
	printf("\n-|-1-|-2-|-3-|-4-|-5-|-6-|-7-|-8-|-9-|-\n");
	printf("\n");

}

int checkFreeSpaces()
{
	int freeSpaces = 81;
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			if (board[i][j] != ' ')
			{
				freeSpaces--;
			}
		}
	}
	return freeSpaces;
}

void playerMove()
{
	int x;
	int y;
	do{
		printf("Enter row #(1-9): ");
		scanf("%d",&x);
		x--;
		printf("Enter col #(1-9): ");
		scanf("%d",&y);
		y--;

		if (board[x][y] != ' ')
		{
			printf("Invalid move!\n");
		}
		else
		{
			board[x][y] = PLAYER;
			system("cls");
			break;
		}
	} while (board[x][y] != ' ');
	
}

void computerMove()
{
	srand((unsigned int)time(0));
	int x;
	int y;
	if(checkFreeSpaces() > 0)
	{
		do
		{
			x = rand() % ROWS;
			y = rand() % COLS;
		} while (board[x][y] != ' ');
		
		board[x][y] = COMPUTER;
		system("cls");
	}
	else
	{
		printWinner(' ');
	}
}

char checkWinner()
{
	//检测横行是否存在5连珠
	for (size_t i = 0; i < ROWS; i++)
	{
		char rstring[10] = "";
		for (size_t j = 0; j < COLS; j++)
		{
			rstring[j] = board[i][j];
		}
		char* returnStr1 = strstr(rstring,"XXXXX");
		char* returnStr2 = strstr(rstring,"OOOOO");

		if(returnStr1 != NULL) return PLAYER;
		if(returnStr2 != NULL) return COMPUTER;
	}
	//检测竖行是否存在五连珠
	for (size_t i = 0; i < COLS; i++)
	{
		char cstring[10] = "";
		for (size_t j = 0; j < ROWS; j++)
		{
			cstring[j] = board[j][i];
		}
		char* returnStr1 = strstr(cstring,"XXXXX");
		char* returnStr2 = strstr(cstring,"OOOOO");

		if(returnStr1 != NULL) return PLAYER;
		if(returnStr2 != NULL) return COMPUTER;
	}
		//检测左上至左下是否存在斜行五连珠
		char lr00[10] = "";
		char lr10[10] = "";
		char lr20[10] = "";
		char lr30[10] = "";
		char lr40d[10] = "";
		char lr01[10] = "";
		char lr02[10] = "";
		char lr03[10] = "";
		char lr04[10] = "";
		//检测左下至右上是否存在斜行五连珠
		char lr40u[10] = "";
		char lr50[10] = "";
		char lr60[10] = "";
		char lr70[10] = "";
		char lr80[10] = "";
		char lr81[10] = "";
		char lr82[10] = "";
		char lr83[10] = "";
		char lr84[10] = "";

	//检测左上至左下是否存在斜行五连珠
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			if(i == j){					//00
				lr00[i] = board[i][j];	
			}
			else if((i - j) == 1) {		//10
				lr10[j] = board[i][j];
			}
			else if((i - j) == 2){		//20
				lr20[j] = board[i][j];
			}
			else if((i-j) == 3){		//30
				lr30[j] = board[i][j];
			}
			else if((i-j) == 4){		//40
				lr40d[j] = board[i][j];
			}
			else if((i-j) == -1){		//01
				lr01[i] = board[i][j];
			}
			else if((i-j) == -2){		//02
				lr02[i] = board[i][j];
			}
			else if((i-j) == -3){		//03
				lr03[i] = board[i][j];
			}
			else if((i-j) == -4){		//04
				lr04[i] = board[i][j];
			}
			else if((i+j) == 4){
				lr40u[j] = board[i][j];
			}
			else if((i+j) == 5){
				lr50[j] = board[i][j];
			}
			else if((i+j) == 6){
				lr60[j] = board[i][j];
			}
			else if((i+j) == 7){
				lr70[j] = board[i][j];
			}
			else if((i+j) == 8){
				lr80[j] = board[i][j];
			}
			else if((i+j) == 9){
				lr81[j-1] = board[i][j];
			}
			else if((i+j) == 10){
				lr82[j-2] = board[i][j];
			}
			else if((i+j) == 11){
				lr83[j-3] = board[i][j];
			}
			else if((i+j) == 12){
				lr83[j-4] = board[i][j];
			}
		}
	}
	//检测左下至右上是否存在斜行五连珠
	for (size_t i = 0; i < ROWS; i++)
	{
		for (size_t j = 0; j < COLS; j++)
		{
			
			if((i+j) == 4){
				lr40u[j] = board[i][j];
			}
			else if((i+j) == 5){
				lr50[j] = board[i][j];
			}
			else if((i+j) == 6){
				lr60[j] = board[i][j];
			}
			else if((i+j) == 7){
				lr70[j] = board[i][j];
			}
			else if((i+j) == 8){
				lr80[j] = board[i][j];
			}
			else if((i+j) == 9){
				lr81[j-1] = board[i][j];
			}
			else if((i+j) == 10){
				lr82[j-2] = board[i][j];
			}
			else if((i+j) == 11){
				lr83[j-3] = board[i][j];
			}
			else if((i+j) == 12){
				lr83[j-4] = board[i][j];
			}
		}
	}
	//判断是否五连珠
		char* lrStr00p = strstr(lr00,"XXXXX");
		char* lrStr00c= strstr(lr00,"OOOOO");

		char* lrStr10p = strstr(lr10,"XXXXX");
		char* lrStr10c= strstr(lr10,"OOOOO");

		char* lrStr20p = strstr(lr20,"XXXXX");
		char* lrStr20c= strstr(lr20,"OOOOO");

		char* lrStr30p = strstr(lr30,"XXXXX");
		char* lrStr30c= strstr(lr30,"OOOOO");

		char* lrStr40dp = strstr(lr40d,"XXXXX");
		char* lrStr40dc= strstr(lr40d,"OOOOO");

		char* lrStr40up = strstr(lr40u,"XXXXX");
		char* lrStr40uc= strstr(lr40u,"OOOOO");

		char* lrStr50p = strstr(lr50,"XXXXX");
		char* lrStr50c= strstr(lr50,"OOOOO");

		char* lrStr60p = strstr(lr60,"XXXXX");
		char* lrStr60c= strstr(lr60,"OOOOO");

		char* lrStr70p = strstr(lr70,"XXXXX");
		char* lrStr70c= strstr(lr70,"OOOOO");

		char* lrStr80p = strstr(lr80,"XXXXX");
		char* lrStr80c= strstr(lr80,"OOOOO");

		char* lrStr01p = strstr(lr01,"XXXXX");
		char* lrStr01c= strstr(lr01,"OOOOO");

		char* lrStr02p = strstr(lr02,"XXXXX");
		char* lrStr02c= strstr(lr02,"OOOOO");

		char* lrStr03p = strstr(lr03,"XXXXX");
		char* lrStr03c= strstr(lr03,"OOOOO");

		char* lrStr04p = strstr(lr04,"XXXXX");
		char* lrStr04c= strstr(lr04,"OOOOO");

		char* lrStr81p = strstr(lr81,"XXXXX");
		char* lrStr81c= strstr(lr81,"OOOOO");

		char* lrStr82p = strstr(lr82,"XXXXX");
		char* lrStr82c= strstr(lr82,"OOOOO");

		char* lrStr83p = strstr(lr83,"XXXXX");
		char* lrStr83c= strstr(lr83,"OOOOO");

		char* lrStr84p = strstr(lr84,"XXXXX");
		char* lrStr84c= strstr(lr84,"OOOOO");

		//判断哪方获胜
		if(lrStr00p != NULL || lrStr10p != NULL || lrStr20p != NULL || lrStr30p != NULL || lrStr40dp != NULL
		|| lrStr40up != NULL|| lrStr50p != NULL || lrStr60p != NULL || lrStr70p != NULL || lrStr80p != NULL 
		|| lrStr01p != NULL || lrStr02p != NULL || lrStr03p != NULL || lrStr04p != NULL
		|| lrStr81p != NULL || lrStr82p != NULL || lrStr83p != NULL || lrStr84p != NULL) return PLAYER;
		
		if(lrStr00c != NULL || lrStr10c != NULL || lrStr20c != NULL || lrStr30c != NULL || lrStr40dc != NULL
		|| lrStr40uc != NULL|| lrStr50c != NULL || lrStr60c != NULL || lrStr70c != NULL || lrStr80c != NULL 
		|| lrStr01c != NULL || lrStr02c != NULL || lrStr03c != NULL || lrStr04c != NULL
		|| lrStr81c != NULL || lrStr82c != NULL || lrStr83c != NULL || lrStr84c != NULL) return COMPUTER;
		
	
	return ' ';
}

void printWinner(char winner)
{
	if(winner == PLAYER)
	{
		printf("YOU WIN!\n");
		printf("\a");
	}
	else if(winner == COMPUTER)
	{
		printf("YOU LOSE!\n");
		printf("\a");
	}
	else
	{
		printf("IT'S A TIE!\n");
		printf("\a");
	}
}