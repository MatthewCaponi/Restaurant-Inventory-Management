#include "InventoryDatabase.h"
#include "AllInventoryHistory.h"
#include "SingleWeekInventoryHistory.h"
#include "LongTermDatabaseMenu.h"
#include "DataIO.h"
#include "MainMenu.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
InventoryDatabase::InventoryDatabase()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void InventoryDatabase::setup()
{

}
void InventoryDatabase::run() 
{

}
void InventoryDatabase::menu()
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
				nextDisplay = new AllInventoryHistory();
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 2:
				nextDisplay = new SingleWeekInventoryHistory();
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 3: 
				nextDisplay = new LongTermDatabaseMenu();
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 4: 
				nextDisplay = new MainMenu();
				nextDisplay->setIsEmployee(isEmployee);
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

void InventoryDatabase::showMenu()
{
	cout << "\n *** INVENTORY DATABASE ***\n";
	cout << "\n Select one of the following:\n\n";
	cout << "    1: Show all past week's inventories" << endl;
	cout << "    2: Search for individual week's inventory" << endl;
	cout << "    3: Return to long term database menu" << endl;
	cout << "    4: Return to main menu" << endl;
}
// Destructors
InventoryDatabase::~InventoryDatabase() {}