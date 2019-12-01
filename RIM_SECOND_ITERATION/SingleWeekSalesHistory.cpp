#include "SingleWeekSalesHistory.h"
#include "EditSingleWeekSalesHistory.h"
#include "SalesDatabase.h"
#include "DataIO.h"
#include "MenuItem.h"
#include <list>

using namespace std;

SingleWeekSalesHistory::SingleWeekSalesHistory()
{

}

void SingleWeekSalesHistory::setup()
{

}

void SingleWeekSalesHistory::run()
{
	ostringstream out;
	list<MenuItem> sales;

	if (content.empty())
	{
		bool answered = false;
		cout << "\n *** SALES REPORT : WEEK SEARCH *** \n\n";
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
				sales = readMenuItemType("#4" + date);
				dateToShow = date.substr(0, 2) + '/' + date.substr(2, 2) + '/' + date.substr(4, 4);
				if (!sales.empty())
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
		sales = readMenuItemType("#4" + date.toDigit());
	}

	system("CLS");

	if (!sales.empty())
	{
		int largestMenu = static_cast<int>(sales.begin()->getName().size());
		for (MenuItem &m : sales)
			largestMenu = (static_cast<int>(m.getName().size()) > largestMenu) ? static_cast<int>(m.getName().size()) : largestMenu;
		out << "\n *** SALES REPORT : WEEK OF " << Date(dateToShow) << " *** " << endl;
		out << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		out << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | amount sold " << endl;
		out << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		double total = 0;
		for (MenuItem &m : sales)
		{
			total += m.getAmountSold() * m.getPrice();
			out << " " << setfill(' ') << setw(largestMenu) << left << m.getName();
			out << " | ";
			out << m.getAmountSold() << endl;
		}
		out << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		out << " Sales total: $" << fixed << setprecision(2) << total << endl;
	}
	else
	{
		cout << " Error with sales." << endl;
		cout << " ";
		system("Pause");
	}

	content = out.str();
	cout << content;

}


void SingleWeekSalesHistory::menu()
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
				nextDisplay = new EditSingleWeekSalesHistory(dateToShow); //both options go back to InventoryDatabase, change when edit function is complete
				nextDisplay->setContent(dateToShow);
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 2:
				nextDisplay = new SalesDatabase();
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

void SingleWeekSalesHistory::showMenu()
{
	cout << " -----------------------------------------\n";
	cout << "\n Select one of the following:\n\n";
	cout << "    1: Edit this week's sales" << endl;
	cout << "    2: Back to sales menu" << endl;
}

SingleWeekSalesHistory::~SingleWeekSalesHistory() {}