#include <iostream>
#include <iomanip>
using namespace std;

void LineSeperation() // function to seperate lines using hyphens
{
	cout << endl;
	for (int i = 0; i < 45; i++)
	{
		cout << "¬";
	}
	cout << endl;
}

float initialCreds = 0;
char yesNo;
int userMenuSelect;
float credits = 0;
int PizzaSizeSelection;
int topppingSelection;
float pizzaPrices[3] = { 3.0, 5.50, 7.25 };
string pizzaSizes[3] = { "7 inch", " 9 inch", "14 inch" };
float toppingPrices[6] = { 0.80, 0.50, 1.00, 0.30, 0.60, 1.20 };
string toppingOptions[6] = { "Ham", "Mushrooms", "Pepperoni", "Olives", "Pineapple", "Extra Cheese" };
float totalToppingCost = 0;
float sizeCost;
float totalCost;

 float TopUp() //funnction to add more creds
{
	
	cout << "How many credits do you wish to add?   ";
	double topUpAmnt;
	cin >> topUpAmnt;

	while (cin.fail() || topUpAmnt < 0) // checks if users input is valid
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Please enter a valid amount: ";
		cin >> topUpAmnt;
	}

	credits = credits + topUpAmnt;
	//cout << endl << "Previous balance:   " << initialCreds << " credits" << endl;
	//initialCreds += topUpAmnt;
	cout << endl << "Your new balance:   " << fixed << setprecision(2) << credits << " credits" << endl;
	
	return credits;
}

char yesNoCheck() //validation check for y or n inputs
{
	cin.clear();
	cin >> yesNo;
	yesNo = tolower(yesNo);
	while (yesNo != 'y' && yesNo != 'n')
	{
		
		cin.ignore(80, '\n');
		cout << "Please enter 'y' or 'n' only  " << endl;
		cin >> yesNo;
	}

	return yesNo;
}

float creditCheck() //function to check if user has sufficient creds or not
{
	if (credits < totalCost)
	{
		do
		{
			cout << "You have insufficient funds. Enter 'y' to top up or 'n' to exit:   ";
			yesNoCheck();
			if (yesNo == 'y')
			{
				TopUp();
			}
			else if (yesNo == 'n')
			{
				exit;
			}

		} while (credits < totalCost);

	}
	
		return credits;
}

void toppings()
{
	LineSeperation();

	cout << endl << setw(32) << "Pizza - Select Toppings" << endl;
	cout << endl << "Please choose from the following toppings:" << endl;
	cout << "   1. Ham " << setw(29) << "[0.80 credits]" << endl;
	cout << "   2. Mushrooms " << setw(23) << "[0.50 credits]" << endl;
	cout << "   3. Pepperoni " << setw(23) << "[1.00 credits]" << endl;
	cout << "   4. Olives " << setw(26) << "[0.30 credits]" << endl;
	cout << "   5. Pineapple " << setw(23) << "[0.60 credits]" << endl;
	cout << "   6. Extra Cheese " << setw(20) << "[1.20 credits]" << endl;
	cout << "   0. Return to Main Menu" << endl;
	LineSeperation();

	do
	{
		cout << "Please enter a number :   " ;
		cin >> topppingSelection;

		while (cin.fail() || topppingSelection < 0 || topppingSelection > 6) // checks if users input is valid
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Please enter a valid number: ";
			cin >> topppingSelection;
		}

		cout << "You selected " << toppingOptions[topppingSelection - 1] << " :   " << fixed << setprecision(2) << toppingPrices[topppingSelection - 1] << " credits" << endl;
		cout << "Do you wish to add another topping? (y/n)   ";
		yesNoCheck();
		totalToppingCost += toppingPrices[topppingSelection - 1];
		
	} while (yesNo != 'n'); //loop asking user if they want to add toppings continuously until they choose no

	sizeCost = pizzaPrices[PizzaSizeSelection - 1];
	totalCost = sizeCost + totalToppingCost;
	LineSeperation();
	cout << endl << "Available balance :   " << fixed << setprecision(2) << credits << " credits" << endl;
	cout << endl << "Pizza Price :   " << setw(6) << fixed << setprecision(2) << sizeCost << " credits" << endl;
	cout << "Topping Price :   " << setw(4) << fixed << setprecision(2) << totalToppingCost << " credits" << endl;
	cout << endl << "Total Cost :   " << setw(7) << fixed << setprecision(2) << totalCost << " credits" << endl;
	LineSeperation();

	creditCheck();
	credits = credits - totalCost;
	cout << endl << "Your new balance :   " << credits << " credits" << endl;
	cout << endl << "Your pizza will be delievered to you shortly." << endl;
	totalToppingCost = 0;
	sizeCost = 0;
	totalCost = 0;
}

int main()
{
	LineSeperation(); //function call

	cout << endl << setw(27) << "UCLAN PIZZA" << endl;
	cout << endl << setw(27) << "Welcome to the UCLan Pizza shop!" << endl;

	do //loop to return to main menu instead of quitting program
	{
		LineSeperation();
		cout << endl << setw(26) << "Main Menu" << endl;
		cout << endl << "   1. Add Credits (Current balance = " << fixed << setprecision(2) << credits << " credits)" << endl;
		cout << "   2. Order Pizza" << endl;
		cout << "   3. Quit" << endl;
		cout << endl << "Select an option by entering a number:   ";
		cin >> userMenuSelect;

		while (cin.fail() || userMenuSelect < 1 || userMenuSelect > 3) // checks if users input is valid
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "Please enter a valid number: ";
			cin >> userMenuSelect;
		}

		switch (userMenuSelect) //switch case used for main menu - 3 options/ 3 cases
		{
		case 1: //case 1 to add credits

			LineSeperation();
			cout << endl << setw(27) << "Add Credits" << endl;
			cout << endl << "Current Credits:   " <<  fixed << setprecision(2) << credits << endl;
			TopUp();

			break;

		case 2: //case 2 to order a pizza

			do
			{
				LineSeperation();
				cout << endl << setw(35) << "Order Pizza - Select Size" << endl;
				cout << endl << "Current balance:   " << credits << endl;
				cout << endl << "All Pizza Sizes:" << endl;
				cout << "   1. 7 inch " << setw(20) << "[3.0 credits]" << endl;
				cout << "   2. 9 inch " << setw(21) << "[5.50 credits]" << endl;
				cout << "   3. 14 inch " << setw(20) << "[7.25 credits]" << endl;
				cout << "   0. Return to Main Menu" << endl;
				LineSeperation();

				cout << endl << "Choose a pizza size :   ";
				cin >> PizzaSizeSelection;

				while (cin.fail() || PizzaSizeSelection < 0 || PizzaSizeSelection > 3) // checks if users input is valid
				{
					cin.clear();
					cin.ignore(80, '\n');
					cout << "Please enter a valid number: ";
					cin >> PizzaSizeSelection;
				}

				switch (PizzaSizeSelection)
				{
				case 1:

					cout << "You have selected a 7 inch pizza." << endl;
					cout << endl << "Pizza Price :   " << fixed << setprecision(2) << pizzaPrices[PizzaSizeSelection - 1] << " credits";
					toppings();

					break;

				case 2:

					cout << "You have selected a 9 inch pizza." << endl;
					cout << endl << "Pizza Price :   " << fixed << setprecision(2) << pizzaPrices[PizzaSizeSelection - 1] << " credits";
					toppings();

					break;

				case 3:

					cout << "You have selected a 14 inch pizza." << endl;
					cout << endl << "Pizza Price :   " << fixed << setprecision(2) << pizzaPrices[PizzaSizeSelection - 1] << " credits";
					toppings();

					break;
				}
				cout << endl << "Would you like to order another pizza? (y/n)   ";
				yesNoCheck();
			
			} while (yesNo != 'n');
			cout << endl << "Your balance is :   " << fixed << setprecision(2) << credits << " credits" << endl;
			
			break;

		case 3: //case 3 to exit
			cout << endl << "Thank you, Goodbye!" << endl;
			exit;
		}

	} while (userMenuSelect != 3);
	

}