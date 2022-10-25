//Name:                 Adnan Ali Mumtaz
//Student ID Number:    20862007 / CE

#include <iostream>
#include <iomanip>
using namespace std;

int Option_Selector;       //Options will be selected with Option_Selecter.
double Credit;             
double Pizza_Price;       
double Topping_Price;      
double Total_Price;        
double Additional_Credit;  //Additional Credit will be added to the Credit(Variable).
double Required_Balance;   //Required_Balance is Credit needed to process the order.
string yesno;              //yesno variable is for users to make decisions.

void yesno_Validation()
{
	//Asking for input
	cout << "Please Enter (Y for Yes) or (N for No)" << endl;
	cout << "Answer: ";
	cin >> yesno;

	//Validating user's Input.
	while (yesno != "y" && yesno != "Y" && yesno != "N" && yesno != "n")
	{
		//Error Message
		cout << " - - - - - - - - - - - - - - - - - -" << endl;
		cout << " Input is invalid!" << endl;
		cout << " Input must be either (Y for Yes) or (N for No)!" << endl;
		cout << " - - - - - - - - - - - - - - - - - -" << endl;

		//Asking for Input again.
		cout << "Answer: ";
		cin >> yesno;
	}
}

void Credit_Validation()
{		
	//Validating user's Input.
	while (cin.fail() || Additional_Credit < 0 || Additional_Credit > 999)
	{
		cin.clear();
		cin.ignore(80, '\n');

		// Error Message.
		cout << " - - - - - - - - - - - - - - - - - -" << endl;
		cout << " Input is Invalid!" << endl;
		cout << " Input must be numbered between 1-999!" << endl;
		cout << " - - - - - - - - - - - - - - - - - -" << endl;

		//Asking for Input again.
		cout << "Please Add Credit: ";
		cin >> Additional_Credit;
	}
}

void DrawBoldline()
{
	//Line to be drawn for the good-looking Interface.
	for (int i = 0; i <=35;  i++)
	{
		cout << "=" ;
	}
	cout << endl;
}

void Checkout()
{
	if (Credit >= Total_Price)//If Available balance more than or equal to Total Cost. 
	{
		DrawBoldline();
		cout << "              Checkout" << endl;
		DrawBoldline();

		cout << endl;
		cout << "  AVAILABLE BALANCE:   " << "'" << fixed << setprecision(2) << Credit << "'" << endl;
		cout << "  --------------------------- " << endl;
		cout << "  PIZZA PRICE:         " << "'" << fixed << setprecision(2) << Pizza_Price << "'" << endl;
		cout << "  TOPPING PRICE:       " << "'" << fixed << setprecision(2) << Topping_Price << "'" << endl;
		cout << "  - - - - - - - - - - - - - - " << endl;
		cout << "  TOTAL PRICE:         " << "'" << fixed << setprecision(2) << Total_Price << "'" << endl;
		cout << "  --------------------------- " << endl;

		Credit -= Total_Price; /*Remaining Credit is being calculated to be given to the user.
							     User can also use this Remaining Credit for another purchase.*/

		cout << "  Curent Balance:      " << "'" << fixed << setprecision(2) << Credit << "'" << endl;
		cout << "  --------------------------- " << endl;
		cout << endl;
	}

	else if (Total_Price > Credit)//If Total Cost is more than Credit. 
	{
		DrawBoldline();
		cout << "              Checkout" << endl;
		DrawBoldline();

		cout << endl;
		cout << "  AVAILABLE BALANCE:   " << "'" << fixed << setprecision(2) << Credit << "'" << endl;
		cout << "  --------------------------- " << endl;
		cout << "  PIZZA PRICE:         " << "'" << fixed << setprecision(2) << Pizza_Price << "'" << endl;
		cout << "  TOPPING PRICE:       " << "'" << fixed << setprecision(2) << Topping_Price << "'" << endl;
		cout << "  - - - - - - - - - - - - - - " << endl;
		cout << "  TOTAL PRICE:         " << "'" << fixed << setprecision(2) << Total_Price << "'" << endl;
		cout << "  --------------------------- " << endl;
		cout << endl;
		
		Required_Balance = Total_Price - Credit; //Needed Credit to be calculate to continue with the order.

		cout << " - - - - - - - - - - - - - - - - - -" << endl;
		cout << " You have insufficient credits. " << endl;
		cout << " You require : '" << fixed << setprecision(2) << Required_Balance << "'" << endl;
		cout << " - - - - - - - - - - - - - - - - - -" << endl;

		DrawBoldline();
		cout << "Would you like to add more Credit?" << endl;
		yesno_Validation();//Validating user's Input. 

		if (yesno == "y" || yesno == "Y")
		{
			DrawBoldline();
			cout << "How much additional credit would you like to add?" << endl;
			cout << "Please Add Credit: ";
			cin >> Additional_Credit;
			Credit_Validation();//Validating the user's Input.

			cout << "-----------------------------------" << endl;
			cout << "'" << fixed << setprecision(2) << Additional_Credit << "'" << " additional credit has been added to your balance!" << endl;
			cout << "-----------------------------------" << endl;

			Credit += Additional_Credit;

			DrawBoldline();
			cout << " -----[" << " Current Credit: " << fixed << setprecision(2) << Credit << " ]-----" << endl;/*Overall Credit after the 
																												  "Additional Credit"
																												   has been added to the local Credit.*/
			cout << "Would you like to continue processing your order?" << endl;
			yesno_Validation(); //Validating the user's Input.

			if (yesno == "y" || yesno == "Y")
			{
				Checkout(); //Funtion to be recalled again, if the user wants to process the order.
			}
		}
	}
}

int main()
{
	DrawBoldline();
	cout << "              PIZZERIA" << endl;
	cout << " -----[" << " Current Credit: " << fixed << setprecision(2) << Credit << " ]-----" << endl;
	DrawBoldline();
	cout << "MAIN MENU" << endl;
	cout << "   1. Add Credit " << endl;
	cout << "   2. Order Pizza" << endl;
	cout << "   0. Exit" << endl;
	cout << endl;
	cout << "Please Enter a Number: ";
	cin >> Option_Selector;

	//Validating user's input.
	while (cin.fail() || Option_Selector != 1 && Option_Selector != 2 && Option_Selector != 0)
	{
		cin.clear();
		cin.ignore(80, '\n');

		//Error Message
		cout << " - - - - - - - - - - - - - - - - - -" << endl;
		cout << " Input is invalid!" << endl;
		cout << " Please Enter a valid value from the \n following options 1, 2, 0!" << endl;
		cout << " - - - - - - - - - - - - - - - - - -" << endl;

		//Asking for input again.
		cout << "Please Enter a Number: ";
		cin >> Option_Selector;
	}

	if (Option_Selector == 1)
	{
		DrawBoldline();
		cout << "              Credit" << endl;
		DrawBoldline();
		cout << "How much Credit would you like to add?" << endl;
		cout << "Please Add Credit: ";
		cin >> Additional_Credit; /*Additional Credit is being asked for input instead of credit, So, when the main() funtion is recalled a head,
								    user can to add more credit as well.*/

		Credit_Validation(); //Validating user's input.
		Credit += Additional_Credit; //Additional Credit is being addded to the Credit.

		cout << " - - - - - - - - - - - - - - - - - -" << endl;
		cout << " '" << fixed << setprecision(2) << Credit << "'" << " credit has been added to \n  your balance!" << endl;
		cout << " - - - - - - - - - - - - - - - - - -" << endl;

		main(); //Main() funtion being recalled again.
	}
	else if (Option_Selector == 2)
	{
		DrawBoldline();
		cout << "            ORDER PIZZA" << endl;
		cout << " -----[" << " Current Credit: " << fixed << setprecision(2) << Credit << " ]-----" << endl;
		DrawBoldline();

		do 	//Pizza code to be excuted.
		{
			cout << "Please choose the Pizza from the following options: " << endl;
			cout << "   1. 7-inch [3.0]" << endl;
			cout << "   2. 9-inch [5.50]" << endl;
			cout << "   3. 14-inch [7.25]" << endl;
			cout << "   0. Return to Main Menu" << endl;
			cout << endl;
			cout << "Please Enter a Number: ";
			cin >> Option_Selector;

			//Validating user's input.
			while (cin.fail() || Option_Selector != 1 && Option_Selector != 2 && Option_Selector != 3 && Option_Selector != 0)
			{
				cin.clear();
				cin.ignore(80, '\n');

				//Error Message.
				cout << " - - - - - - - - - - - - - - - - - -" << endl;
				cout << " Input is invalid!" << endl;
				cout << " Please Enter a valid value from the \n following options 1, 2, 3, 0!" << endl;
				cout << " - - - - - - - - - - - - - - - - - -" << endl;

				//Asking for input.
				cout << "Please Enter a Number: ";
				cin >> Option_Selector;
			}

			cout << " - - - - - - - - - - - - - - - - - -" << endl;
			if (Option_Selector == 1)
			{
				cout << " You Have Selected 7-inch Pizza!" << endl;
				Pizza_Price = 3.00;
			}
			else if (Option_Selector == 2)
			{
				cout << " You Have Selected 9-inch Pizza!" << endl;
				Pizza_Price = 5.50;
			}
			else if (Option_Selector == 3)
			{
				cout << " You Have Selected 14-inch Pizza!" << endl;
				Pizza_Price = 7.25;
			}
			else if (Option_Selector == 0)
			{
				main();
			}
			cout << " - - - - - - - - - - - - - - - - - -" << endl;

			do //Topping code to be excuted.
			{
				DrawBoldline();
				cout << "Please choose the Topping from the following options: " << endl;
				cout << "   1. Ham          [0.80]" << endl;
				cout << "   2. Mushrooms    [0.50]" << endl;
				cout << "   3. Pepperoni    [1.00]" << endl;
				cout << "   4. Olives       [0.30]" << endl;
				cout << "   5. Pineapple    [0.60]" << endl;
				cout << "   6. Extra Cheese [1.20]" << endl;
				cout << "   0. Return to Main Menu" << endl;
				cout << endl;
				cout << "Enter a Number: ";
				cin >> Option_Selector;

				//Validating users's Input.
				while (cin.fail() || Option_Selector != 1 && Option_Selector != 2 && Option_Selector != 3 && Option_Selector != 4 && Option_Selector != 5 && Option_Selector != 6 && Option_Selector != 0)
				{
					cin.clear();
					cin.ignore(80, '\n');

					//Error Message
					cout << " - - - - - - - - - - - - - - - - - -" << endl;
					cout << " Input is invalid!" << endl;
					cout << " Please Enter a valid value from the \n following options 1,2,3,4,5,6,0!" << endl;
					cout << " - - - - - - - - - - - - - - - - - -" << endl;

					//Asking for Input again.
					cout << "Enter a Number: ";
					cin >> Option_Selector;
				}

				cout << " - - - - - - - - - - - - - - - - - -" << endl; 
				if (Option_Selector == 1)
				{
					Topping_Price += 0.80;
					cout << " You have added 'Ham Topping' \n to your Pizza!" << endl;
				}
				else if (Option_Selector == 2)
				{
					Topping_Price += 0.50;
					cout << " You have added 'Mushroom Topping' \n to your Pizza!" << endl;
				}
				else if (Option_Selector == 3)
				{
					Topping_Price += 1.00;
					cout << " You have added 'Pepperoni Topping' \n to your Pizza!" << endl;
				}
				else if (Option_Selector == 4)
				{
					Topping_Price += 0.30;
					cout << " You have added 'Olives Topping' \n to your Pizza!" << endl;
				}
				else if (Option_Selector == 5)
				{
					Topping_Price += 0.60;
					cout << " You have added 'Pineapple Topping' \n to your Pizza!" << endl;
				}
				else if (Option_Selector == 6)
				{
					Topping_Price += 1.20;
					cout << " You have added 'Extra Cheese Topping' \n to your Pizza!" << endl;
				}
				else if (Option_Selector == 0)
				{
					main();
				}
				cout << " - - - - - - - - - - - - - - - - - -" << endl;

				DrawBoldline();
				cout << "Would you like to add more toppings? " << endl; 
				yesno_Validation();

			} while (yesno == "y" || yesno == "Y"); //Topping Code to repeat.

			Total_Price = Pizza_Price + Topping_Price;
			Checkout(); //Once done with ordering, Checkout() funtion will be called. 

			DrawBoldline();
			cout << "Would you like to order more pizza?" << endl;
			yesno_Validation(); //Validating user's Input.

			if (yesno == "N" || yesno == "n")
			{
				DrawBoldline();
				cout << " - - - - - - - - - - - - - - - - - -" << endl;
				cout << " You'll take Home:     " << fixed << setprecision(2) << "'" << Credit << "'" << endl;
				cout << " - - - - - - - - - - - - - - - - - -" << endl;
				DrawBoldline();
				cout << "Thank You, Good Bye!" << endl;
			}
			DrawBoldline(); //If another pizza isn't being ordered, the code will exit here.

			//Pizza and Topping prices set to 0 for the another order, if user says Yes.
			Pizza_Price = 0;
			Topping_Price = 0;
		} while (yesno == "y" || yesno == "Y"); //If another pizza is being ordered. The code will repeat all over again.
	}
}