#include "MainMenu.h"
#include "LongTermDatabaseMenu.h"
#include "CurrentDatabaseMenu.h"
#include "CommentsBoardMenu.h"
#include "RestaurantMenuAndInventoryView.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
MainMenu::MainMenu() : Display()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void MainMenu::setup()
{

}

void MainMenu::run()
{
	
}

void MainMenu::menu()
{
	bool answered = false;
	int choice;
	string response;
	showMenu();
	cout << endl;
	cout << " ";
	getline(cin, response);
	while (!answered)
	{
		if (isValidResponse(response, choice, 1, 5))
		{
			switch (choice)
			{
			case 1:
				nextDisplay = new CurrentDatabaseMenu();
				answered = true;
				break;
			case 2:
				nextDisplay = new LongTermDatabaseMenu();
				answered = true;
				break;
			case 3:
				nextDisplay = new CommentsBoardMenu();
				answered = true;
				break;
			case 4:
				nextDisplay = new RestaurantMenuAndInventoryView();
				answered = true;
				break;
			case 5:
			default:
				nextDisplay = nullptr;
				answered = true;
				break;
			}
		}
		else
		{
			system("CLS");
			showMenu();
			cout << " That's an invalid choice. Try again." << endl;
			cout << " ";
			getline(cin, response);
		}
	}
}

void MainMenu::showMenu()
{
	if (isEmployee)
	{
		cout << "\n *** MAIN MENU ***\n";
		cout << "\ nSelect one of the following:\n\n";
		cout << "    1: Enter / view current week's records" << endl;
		cout << "    2: View past weeks' records" << endl;
		cout << "    3: Submit onto the suggestion board" << endl;
		cout << "    4: View the restaurant menu and ingredients list" << endl;
 		cout << "    5: To exit" << endl;
	}
	else
	{
		cout << "\n *** MAIN MENU ***\n";
		cout << "\n Select one of the following:\n\n";
		cout << "    1: Enter / view current week's records" << endl;
		cout << "    2: View past weeks' records" << endl;
		cout << "    3: View suggestion board" << endl;
		cout << "    4: View the restaurant menu and ingredients list" << endl;
		cout << "    5: To exit" << endl;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
MainMenu::~MainMenu() {};