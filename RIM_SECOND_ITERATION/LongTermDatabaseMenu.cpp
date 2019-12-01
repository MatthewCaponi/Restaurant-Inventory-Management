#include "LongTermDatabaseMenu.h"
#include "MainMenu.h"
#include "InventoryDatabase.h"
#include "SalesDatabase.h"
#include "WasteDatabase.h"
#include "OrderDatabase.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
LongTermDatabaseMenu::LongTermDatabaseMenu() : Display()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void LongTermDatabaseMenu::setup()
{

}

void LongTermDatabaseMenu::run()
{

}

void LongTermDatabaseMenu::menu()
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
				nextDisplay = new InventoryDatabase();
				answered = true;
				break;
			case 2:
				nextDisplay = new SalesDatabase();
				answered = true;
				break;
			case 3:
				nextDisplay = new OrderDatabase();
				answered = true;
				break;
			case 4:
				nextDisplay = new WasteDatabase();
				answered = true;
				break;
			case 5:
				nextDisplay = new MainMenu();
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

void LongTermDatabaseMenu::showMenu()
{
	cout << "\n *** LONG TERM DATABASE MENU ***\n";
	cout << "\n Select one of the following:\n\n";
	cout << "    1: View inventory history" << endl;
	cout << "    2: View sales history" << endl;
	cout << "    3: View order history" << endl;
	cout << "    4: View waste history" << endl;
	cout << "    5: Back to main menu" << endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
LongTermDatabaseMenu::~LongTermDatabaseMenu() {}