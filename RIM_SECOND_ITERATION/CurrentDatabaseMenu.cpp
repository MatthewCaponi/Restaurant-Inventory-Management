#include "CurrentDatabaseMenu.h"
#include "MainMenu.h"
#include "CurrentDatabase.h"
#include "WasteReport.h"
#include "OrderReport.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
CurrentDatabaseMenu::CurrentDatabaseMenu() : Display()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void CurrentDatabaseMenu::setup()
{

}

void CurrentDatabaseMenu::run()
{

}

void CurrentDatabaseMenu::menu()
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
		if (isValidResponse(response, choice, 1, 4))
		{
			switch (choice)
			{
			case 1:
				nextDisplay = new CurrentDatabase();
				answered = true;
				break;
			case 2:
				nextDisplay = new WasteReport();
				answered = true;
				break;
			case 3:
				nextDisplay = new OrderReport();
				answered = true;
				break;
			case 4:
				nextDisplay = new MainMenu();
				answered = true;
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

void CurrentDatabaseMenu::showMenu()
{
	cout << "\n *** CURRENT DATABASE MENU ***\n";
	cout << "\n Select one of the following:\n\n";
	cout << "    1: Enter current inventory" << endl;
	cout << "    2: View waste report" << endl;
	cout << "    3: View suggested order report" << endl;
	cout << "    4: Back to main menu" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
CurrentDatabaseMenu::~CurrentDatabaseMenu() {}