// declaring all libraries needed
#include <iostream>
#include <ctime> // for time functions
#include <cstdlib> // for rand and srand functions
#include <conio.h> // for key function
#include <windows.h>  // for sleep function
#include <string> // for centering text function
#include <iomanip> // for centering text function
using namespace std;

// declaring these as global variables as they are used in multiple functions
int credits = 100; // the starting amount the user will have
int bet; // the amount the user will bet

void slow_print(const string& message) // this function prints each character of a string a certain time apart which allows to give the text a typewriter sort of effect
{
	for (const char c : message) // This loop counts the number of character in a string so it can loop around that amount of times
	{
		cout << c; // This prints each character in the string separately
		Sleep(30); // This is to add a delay of 30ms between each character being printed to the screen
	}
}

void centertext(string text) // Function to center text 
{
	for (int i = 0; i < 40; i++) cout << " "; // prints space for 40 characters along
	int console_width = 40;// Width of console
	int len = text.length();// Length of string.
	if (len % 2 == 0) text += " ";
	cout << setw((console_width / 2) + len / 2)\
		<< right << text << endl;
	for (int i = 0; i < 40; i++) cout << " "; // prints space for 40 characters along
}

int nojackpot() // Screen for when user loses
{
	credits = credits - bet; // subtracts the bet from the total credits
	centertext("You have lost try again");
	return credits, bet;
}
int smalljackpot() // This is the function for when the user wins the smaller jackpot
{
	credits = credits - bet; // subtracts the bet from the total credits
	int payout = bet * 2; // Creates variable called payout which is how much the user has won for this jackpot
	credits = credits + payout; // Adds the payout to the total number of credits
	centertext("You have won the small jackpot!");
	return bet, credits;
}

int bigjackpot() // This is the function for when the user wins the big jackpot
{
	credits = credits - bet; // subtracts the bet from the total credits
	int payout = bet * 5; // Creates variable called payout which is how much the user has won for this jackpot
	credits = credits + payout; // Adds the payout to the total number of credits
	centertext("You have won the BIG jackpot!");
	return bet, credits;
}

int game() // This is where the main game will take place
{
	srand(time(0)); //intialise random num generator using time
	//Variable declaration
	int column1[3];
	int column2[3];
	int column3[3];
	int wheel1 = 1; // state of the wheel, 0 = stop, 1 = run
	int wheel2 = 1; // state of the wheel, 0 = stop, 1 = run
	int wheel3 = 1; // state of the wheel, 0 = stop, 1 = run
	char key; // players input data

	cout << "You have " << credits << " credits" << endl;
	cout << "Please place a bet" << endl;
	cin >> bet;

	if (credits >= bet) // This creates input validation so the user cannot enter more money than they have
	{
		while (wheel1)
		{
			for (int i = 0; i < 3; i++)
			{
				Sleep(50); //Slows down how fast the slot machine is moving 
				column1[i] = rand() % 6 + 1; //generate a random number between 1 and 6
				column2[i] = rand() % 6 + 1; //generate a random number between 1 and 6
				column3[i] = rand() % 6 + 1; //generate a random number between 1 and 6
			}
			system("CLS"); // Clears screen so mulitple values don't appear
			for (int i = 0; i < 47; i++) cout << " "; // centers the slot machine by printing space for 47 characters then displaying the slot machine
			cout << "|"<< column1[0] << "|" << column2[0] << "|" << column3[0] << "|" << endl;
			for (int i = 0; i < 47; i++) cout << " ";
			cout << "|" << column1[1] << "|" << column2[1] << "|" << column3[1] << "|" << endl;
			for (int i = 0; i < 47; i++) cout << " ";
			cout << "|" << column1[2] << "|" << column2[2] << "|" << column3[2] << "|" << endl;

			if (_kbhit()) // waits for keyboard input
			{
				// get keyboard data, and filter it 
				key = toupper(_getch());
				// is player trying to exit, if so exit
				if (key == 'Q' || key == 27)
				{
					wheel1 = 0;
				}
			}
		}

		while (wheel2)
		{

			for (int i = 0; i < 3; i++)
			{
				Sleep(50); //Slows down how fast the slot machine is moving 
				column2[i] = rand() % 6 + 1; //generate a random number between 1 and 6
				column3[i] = rand() % 6 + 1; //generate a random number between 1 and 6
			}
			system("CLS"); // Clears screen so mulitple values don't appear
		
			for (int i = 0; i < 47; i++) cout << " "; // centers the slot machine by printing space for 47 characters then displaying the slot machine
			cout << "|" << column1[0] << "|" << column2[0] << "|" << column3[0] << "|" << endl;
			for (int i = 0; i < 47; i++) cout << " ";
			cout << "|" << column1[1] << "|" << column2[1] << "|" << column3[1] << "|" << endl;
			for (int i = 0; i < 47; i++) cout << " ";
			cout << "|" << column1[2] << "|" << column2[2] << "|" << column3[2] << "|" << endl;

			if (_kbhit()) // waits for keyboard input
			{
				// get keyboard data, and filter it 
				key = toupper(_getch());
				// is player trying to exit, if so exit
				if (key == 'Q' || key == 27)
				{
					wheel2 = 0;
				}
			}
		}

		while (wheel3)
		{
			for (int i = 0; i < 3; i++)
			{
				Sleep(50); //Slows down how fast the slot machine is moving 
				column3[i] = rand() % 6 + 1; //generate a random number between 1 and 6
			}
			system("CLS"); // Clears screen so mulitple values don't appear

			for (int i = 0; i < 47; i++) cout << " "; // centers the slot machine by printing space for 47 characters then displaying the slot machine
			cout << "|" << column1[0] << "|" << column2[0] << "|" << column3[0] << "|" << endl;
			for (int i = 0; i < 47; i++) cout << " ";
			cout << "|" << column1[1] << "|" << column2[1] << "|" << column3[1] << "|" << endl;
			for (int i = 0; i < 47; i++) cout << " ";
			cout << "|" << column1[2] << "|" << column2[2] << "|" << column3[2] << "|" << endl;

			if (_kbhit()) // waits for keyboard input
			{
				// get keyboard data, and filter it 
				key = toupper(_getch());
				// is player trying to exit, if so exit
				if (key == 'Q' || key == 27)
				{
					wheel3 = 0;
				}
			}
		}

		if (column1[1] == column2[1] || column1[1] == column3[1] || column2[1] == column3[1])
		{
			system("CLS"); // Clears screen so the payout can be displayed
			smalljackpot();
		}

		if (column1[1] == column2[1] && column1[1] == column3[1])
		{
			system("CLS"); // Clears screen so the payout can be displayed
			bigjackpot();
		}

		if (column1[1] != column2[1] && column1[1] != column3[1] && column2[1] != column3[1])
		{
			system("CLS"); // Clears screen so the payout can be displayed
			nojackpot();
		}

	}
	else
	{
	slow_print("The amount you have entered is invalid ");
	}

	system("pause");
	return 0;
}

int main() // This is the main program where the game function will be called 
{
	int endprogram = 1; // This is the state of the game, where 0 = not running, and any other number means it is running

	while (endprogram != 0)
	{
		game();

		slow_print("Do you want to stop playing? If so please enter zero "); // Allows the user to stop playing the game
		cin >> endprogram; 
	}

	return 0;
}