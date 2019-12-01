#include "SingleWeekSalesHistory.h"
#include "EditSingleWeekSalesHistory.h"
#include "DataIO.h"
#include "MenuItem.h"
#include <list>

using namespace std;

EditSingleWeekSalesHistory::EditSingleWeekSalesHistory(const string &newDateToEdit)
{
	dateToEdit = newDateToEdit;
}

void EditSingleWeekSalesHistory::setup()
{

}

void EditSingleWeekSalesHistory::run()
{
	Date editingDate(dateToEdit);
	list<MenuItem> menuSold = readMenuItems();
	list<Ingredient> ingredientsUsed = readIngredients();

	int largestMenu = static_cast<int>(menuSold.begin()->getName().size());
	for (const MenuItem &m : menuSold)
		largestMenu = (static_cast<int>(m.getName().size()) > largestMenu) ? static_cast<int>(m.getName().size()) : largestMenu;

	list<MenuItem>::iterator menuSoldIt = menuSold.begin();
	while (menuSoldIt != menuSold.end())
	{
		system("CLS");

		// PRINT FORMATTING
		cout << "\n *** MENU ITEMS SOLD *** \n" << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		cout << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | amount sold " << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;

		list<MenuItem>::iterator printIt = menuSold.begin();
		while (printIt != menuSoldIt)
		{
			cout << " " << setfill(' ') << setw(largestMenu) << left << printIt->getName();
			cout << " | ";
			cout << printIt->getAmountSold() << endl;
			++printIt;
		}
		cout << endl;
		// END PRINT FORMATTING
		cout << " How many " << menuSoldIt->getName() << " were sold (rounded down, to the nearest whole?" << endl;

		string line;
		bool answered = false;
		while (!answered)
		{
			cout << " ";
			getline(cin, line);
			answered = true;
			for (char c : line)
			{
				if (!isdigit(c))
					answered = false;
			}

			if (line.empty()) answered = false;

			if (!answered)
			{
				system("CLS");
				cout << "\n *** MENU ITEMS SOLD *** \n" << endl;
				cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
				cout << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | amount sold " << endl;
				cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
				printIt = menuSold.begin();
				while (printIt != menuSoldIt)
				{
					cout << " " << setfill(' ') << setw(largestMenu) << left << printIt->getName();
					cout << " | ";
					cout << printIt->getAmountSold() << endl;
					++printIt;
				}
				cout << endl;
				cout << " Invalid response. How many " << menuSoldIt->getName() << " were sold (rounded down, to the nearest whole)?" << endl;
			}
		}
		int amount = stoi(line);
		menuSoldIt->setAmountSold(amount);
		list<Ingredient> ingredientsUsedInMenu = menuSoldIt->getAmountIngredientsUsed();

		for (Ingredient &iMenu : ingredientsUsedInMenu)
		{
			for (Ingredient &i : ingredientsUsed)
			{
				if (iMenu == i)
					i.setAmount(i.getAmount() + iMenu.getAmount());
			}
		}
		++menuSoldIt;
	}
	system("CLS");

	// PRINT FORMATTING
	cout << "\n *** MENU ITEMS SOLD *** \n" << endl;
	cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
	cout << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | amount sold " << endl;
	cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;

	for (MenuItem &m : menuSold)
	{
		cout << " " << setfill(' ') << setw(largestMenu) << left << m.getName();
		cout << " | ";
		cout << m.getAmountSold() << endl;
	}
	cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
	cout << " " << setfill(' ') << setw(largestMenu) << left << "ingredient" << " | amount used " << endl;
	cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
	for (Ingredient &i : ingredientsUsed)
	{
		cout << " " << setfill(' ') << setw(largestMenu) << left << i.getName();
		cout << " | ";
		cout << i.getAmount() << endl;
	}
	cout << endl;
	cout << " ";
	system("Pause");

	writeMenuItemType(menuSold, editingDate.beginWeek(), 4);
	list<Ingredient> ideal = readIngredientType("#0" + editingDate.beginWeek().toDigit());
	list<Ingredient> waste = readIngredientType("#1" + editingDate.beginWeek().toDigit());

	for (Ingredient &i : ideal)
	{
		for (Ingredient &u : ingredientsUsed)
		{
			if (i == u)
				i.setAmount(i.getAmount() - u.getAmount());
		}
	}

	for (Ingredient &w : waste)
	{
		for (Ingredient &i : ideal)
		{
			if (w == i)
				w.setAmount(i.getAmount() - w.getAmount());
		}
	}

	writeIngredientType(waste, editingDate.beginWeek(), 2);

	// CALCULATE ORDER
	list<Ingredient> order = readIngredientType("#1" + editingDate.beginWeek().toDigit());

	for (Ingredient &o : order)
	{
		for (Ingredient &u : ingredientsUsed)
		{
			if (u == o)
			{
				o.setAmount((u.getAmount() - o.getAmount() < 0) ? 0 : u.getAmount() - o.getAmount());
			}
		}
	}

	writeIngredientType(order, editingDate.beginWeek(), 3);

}

void EditSingleWeekSalesHistory::menu()
{
	nextDisplay = new SingleWeekSalesHistory();
	nextDisplay->setContent(content);
}

EditSingleWeekSalesHistory::~EditSingleWeekSalesHistory()
{

}