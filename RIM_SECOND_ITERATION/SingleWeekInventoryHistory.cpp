#include "SingleWeekInventoryHistory.h"
#include "EditSingleWeekInventoryHistory.h"
#include "InventoryDatabase.h"
#include "DataIO.h"
#include "Ingredient.h"
#include <list>

using namespace std;

SingleWeekInventoryHistory::SingleWeekInventoryHistory()
{

}

void SingleWeekInventoryHistory::setup()
{

}

void SingleWeekInventoryHistory::run()
{
	ostringstream out;
	list<Ingredient> BOW, EOW;

	if (content.empty())
	{
		bool answered = false;
		cout << "\n *** INVENTORY RECORDS : WEEK SEARCH *** \n\n";
		cout << " Please enter the start date of the week (format mmddyyyy): ";
		while (!answered)
		{
			string date;
			getline(cin, date);

			if (date.size() < 8)
			{
				system("CLS");
				cout << "\n *** SALES REPORT : WEEK SEARCH *** \n";
				cout << " Invalid date." << endl;
				cout << " Please enter the start date of the week (format mmddyyyy): ";

			}
			else
			{
				BOW = readIngredientType("#0" + date);
				EOW = readIngredientType("#1" + date);
				dateToShow = date.substr(0, 2) + '/' + date.substr(2, 2) + '/' + date.substr(4, 4);
				if (!EOW.empty() || !BOW.empty())
					answered = true;
				else
				{
					system("CLS");
					cout << "\n *** SALES REPORT : WEEK SEARCH *** \n";
					cout << " Invalid date / no records." << endl;
					cout << " Please enter the start date of the week (format mmddyyyy): ";
				}
			}		
		}
	}
	else
	{
		dateToShow = content;
		Date date(dateToShow);
		BOW = readIngredientType("#0" + date.toDigit());
		EOW = readIngredientType("#1" + date.toDigit());
	}

	system("CLS");

	if (!BOW.empty())
	{
		int largestIng = static_cast<int>(BOW.begin()->getName().size());
		for (Ingredient &i : BOW)
			largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;
		out << "\n *** BEGINNING OF WEEK INVENTORY REPORT : WEEK OF " << Date(dateToShow) << " *** " << endl;
		out << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		out << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
		out << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		for (Ingredient &i : BOW)
		{
			out << " " << setfill(' ') << setw(largestIng) << left << i.getName();
			out << " | ";
			out << i.getAmount() << endl;
		}
	}
	else
	{
		cout << " Error with BOW." << endl;
		system("Pause");
	}
	
	if (!EOW.empty())
	{
		int largestIng = static_cast<int>(EOW.begin()->getName().size());
		for (Ingredient &i : EOW)
			largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;
		out << "\n *** END OF WEEK INVENTORY REPORT : WEEK OF " << Date(dateToShow) << " *** " << endl;
		out << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		out << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
		out << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		for (Ingredient &i : EOW)
		{
			out << " " << setfill(' ') << setw(largestIng) << left << i.getName();
			out << " | ";
			out << i.getAmount() << endl;
		}
	}
	else
	{
		cout << " Error with EOW." << endl;
		cout << " ";
		system("Pause");
	}

	content = out.str();
	cout << content;
}


void SingleWeekInventoryHistory::menu()
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
		if (isValidResponse(response, choice, 1, 2))
		{
			switch (choice)
			{
			case 1:
				nextDisplay = new EditSingleWeekInventoryHistory(dateToShow); //both options go back to InventoryDatabase, change when edit function is complete
				nextDisplay->setContent(dateToShow);
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 2:
				nextDisplay = new InventoryDatabase();
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			}
		}
		else
		{
			system("CLS");
			cout << content;
			showMenu();
			cout << " That's an invalid choice. Try again." << endl;
			cout << " ";
			getline(cin, response);
		}
	}

}

void SingleWeekInventoryHistory::showMenu()
{
	cout << " -----------------------------------------\n";
	cout << "\n Select one of the following:\n\n";
	cout << "    1: Edit this week's inventory" << endl;
	cout << "    2: Back to inventory menu" << endl;
}

SingleWeekInventoryHistory::~SingleWeekInventoryHistory() {}