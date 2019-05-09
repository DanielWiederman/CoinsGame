#include<stdio.h>
#define MIN_CELLS 10
#define MAX_CELLS 25
#define COINS 4

void print_welcome_message();
int get_cellnum();
void place_coins(int coins[], int cellnum);
void draw_board(int coins[], int cellnum);
int gameover(int coins[]);
void make_move(int coins[], int player_num);
void print_game_summary(int player_num);


int main(){
	int coins[COINS];
	int player_num = 1;
	int cellnum;
	print_welcome_message();
	cellnum = get_cellnum();
	place_coins(coins, cellnum);
	draw_board(coins, cellnum);
	while (!(gameover(coins))) 
	{
		make_move(coins, player_num);
		draw_board(coins, cellnum);
		player_num = 3 - player_num;
	 }
	print_game_summary(3-player_num);
	system("pause");
	return 0;
}


void print_welcome_message()
{
	printf("Welcome 'Player 1' and 'Player 2' to the Game Of Coins! Only the fittest survive.");
	printf("\n");
}

int get_cellnum()
{
	int cellnum;
	printf("Please choose how much cells are going to be in the board (between 10 and 25): ");
	scanf("%d", &cellnum);
	printf("\n");
	if (cellnum < MIN_CELLS || cellnum > MAX_CELLS) //Check if the cellnum chosed by the player is legal.
	{
		printf("Error, not a valid number");
		printf("\n");
		get_cellnum(); //If the number is illegal the function will call itself again.
	}
	else
	{
		return cellnum;
	}
}

void place_coins(int coins[], int cellnum)
{
	int i;
	printf("Please chose where to put the coins in the board\n");
	for (i = 1; i < COINS+1; i++)
	{
		scanf("%d", &coins[i]);
		if (coins[i] > cellnum || coins[i] < 1) // Check if the coins number inst higher than cell numbers.
		{
			printf("Invalid postion please chose another number");
			i--;
		}

	}
}

void draw_board(int coins[], int cellnum)
{

	int i;
	for (i = 0; i < cellnum+1; i++) // First loop to print the 'ceiling' as one unit.
	{
		printf("---"); 
	}
	printf("-");
	printf("\n");
	for (i = 1; i < cellnum+1; i++) // Second loop to print the upper cell as one unit.
	{
		if (coins[1] == i || coins[2] == i || coins[3] == i || coins[4] == i) //comparing if there is a coin inside the cell.
		{
			printf("|**");
		}
		else
		{
			printf("|  ");
		}
	}
	printf("|");
	printf("\n");
	for (i = 1; i < cellnum+1; i++) // Third loop to print the botton cell as one unit.
	{
		if (coins[1] == i || coins[2] == i || coins[3] == i || coins[4] == i) //comparing if there is a coin inside the cell.
		{
			printf("|**");
		}
		else
		{
			printf("|  ");
		}
	}
	printf("|");
	printf("\n");
	for (i = 0; i < cellnum+1; i++) // Four loop to print the 'floor' as one unit.
	{
		printf("---");
	}
	printf("-");
	printf("\n");
}

int gameover(int coins[])
{
	if (coins[1] + coins[2] + coins[3] + coins[4] == 10) // check the sum of the coins, if it equal to 10 its mean game over.
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void make_move(int coins[], int player_num)
{
	int coin_num, answer, moves;
	printf("It's your turn %d, please which coin do you wish to play (1-4)?   ", player_num);
	scanf("%d", &coin_num);
	printf("\n");
	while (1)
	{
		if (coin_num > 4 || coin_num < 1) //Checking if it took coin between 1-4
		{
			printf("Invalid coin\n");
			make_move(coins, player_num);
		}
		printf("Your chosed coin %d location is in cell %d \n Type '1' = to chose another coin or type any other number to continue\n",coin_num, coins[coin_num]);//Checking the coin location in the cell
		scanf("%d", &answer);
		printf("\n");
		if (answer == 1)// giving the option if the player want to change the coin before starting his turn.
		{
			make_move(coins, player_num);
		}
		else
		{
			break;
		}
	}
	printf("Please chose how many cells you want to move your coin?\n\n WARNING: \n(a single cell cant contain 2 coins)\n(You cant go beyond cell 1)\n");
	while (1)
	{
		scanf("%d", &moves);
		if (coins[coin_num] - moves < 1 || coins[coin_num] - moves == coins[1] || coins[coin_num] - moves == coins[2] || coins[coin_num] - moves == coins[3] || coins[coin_num] - moves == coins[4]) //Checking the amount of movement in the cell if it is legal - dosent go lower than 1 and no double coins in a single cell.
		{
			printf("Illegal action please chose again\n");
			continue;
		}
		else
		{
			coins[coin_num] -= moves;
			break;
		}
	}
}

void print_game_summary(int player_num)
{
	printf("%d Is the winner! GG WP.", player_num);
}

//לסדר מקרי קצה שניתן לבחור מטבע שאין מה לעשות איתו.