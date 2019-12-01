#include "SalesDatabase.h"
#include "AllSalesHistory.h"
#include "SingleWeekSalesHistory.h"
#include "LongTermDatabaseMenu.h"
#include "DataIO.h"
#include "MainMenu.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
SalesDatabase::SalesDatabase()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void SalesDatabase::setup()
{

}
void SalesDatabase::run()
{

}
void SalesDatabase::menu()
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
				nextDisplay = new AllSalesHistory();
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 2:
				nextDisplay = new SingleWeekSalesHistory();
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

void SalesDatabase::showMenu()
{
	cout << "\n *** Sales DATABASE ***\n";
	cout << "\n Select one of the following:\n\n";
	cout << "    1: Show all past week's sales" << endl;
	cout << "    2: Search for individual week's sales" << endl;
	cout << "    3: Return to long term database menu" << endl;
	cout << "    4: Return to main menu" << endl;
}
// Destructors
SalesDatabase::~SalesDatabase() {}