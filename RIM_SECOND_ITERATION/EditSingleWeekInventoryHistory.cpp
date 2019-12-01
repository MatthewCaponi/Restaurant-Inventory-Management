 #include "SingleWeekInventoryHistory.h"
#include "EditSingleWeekInventoryHistory.h"
#include "DataIO.h"
#include "MenuItem.h"
#include <list>

using namespace std;

EditSingleWeekInventoryHistory::EditSingleWeekInventoryHistory(const string &newDateToEdit)
{
	dateToEdit = newDateToEdit;
}

void EditSingleWeekInventoryHistory::setup()
{

}

void EditSingleWeekInventoryHistory::run()
{
	Date editingDate(dateToEdit);
	list<Ingredient> ingredients = readIngredients();
	list<Ingredient> BOWInventory = ingredients, EOWInventory = ingredients;
	list<Ingredient> ingredientsUsed = ingredients;

	int largestIng = static_cast<int>(BOWInventory.begin()->getName().size());
	for (Ingredient &i : BOWInventory)
		largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;

	list<Ingredient>::iterator BOWInvIt = BOWInventory.begin();
	while (BOWInvIt != BOWInventory.end())
	{
		system("CLS");

		// PRINT FORMATTING
		cout << "\n *** BEGINNING OF WEEK INVENTORY *** \n" << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;

		list<Ingredient>::iterator printIt = BOWInventory.begin();
		while (printIt != BOWInvIt)
		{
			cout << " " << setfill(' ') << setw(largestIng) << left << printIt->getName();
			cout << " | ";
			cout << printIt->getAmount() << endl;
			++printIt;
		}

		cout << endl;
		// END PRINT FORMATTING

		cout << " How many " << BOWInvIt->getName() << " are in stock at the beginning of the week (rounded down, to the nearest whole)?" << endl;

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
				cout << "\n *** BEGINNING OF WEEK INVENTORY *** \n" << endl;
				cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
				cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
				cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
				printIt = BOWInventory.begin();
				while (printIt != BOWInvIt)
				{
					cout << " " << setfill(' ') << setw(largestIng) << left << printIt->getName();
					cout << " | ";
					cout << printIt->getAmount() << endl;
					++printIt;
				}
				cout << endl;
				cout << " Invalid response. How many " << BOWInvIt->getName() << " are in stock at the beginning of the week (rounded down, to the nearest whole)?" << endl;
			}
		}

		int amount = stoi(line);
		BOWInvIt->setAmount(amount);

		++BOWInvIt;
	}
	system("CLS");

	// PRINTING FORMATTING
	cout << "\n *** BEGINNING OF WEEK INVENTORY *** \n" << endl;
	cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
	cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
	cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
	for (Ingredient &i : BOWInventory)
	{
		cout << " " << setfill(' ') << setw(largestIng) << left << i.getName();
		cout << " | ";
		cout << i.getAmount() << endl;
	}
	cout << endl;
	cout << " ";
	system("Pause");
	
	list<Ingredient>::iterator EOWInvIt = EOWInventory.begin();
	while (EOWInvIt != EOWInventory.end())
	{
		system("CLS");

		// PRINT FORMATTING
		cout << "\n *** END OF WEEK INVENTORY *** \n" << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;

		list<Ingredient>::iterator printIt = EOWInventory.begin();
		while (printIt != EOWInvIt)
		{
			cout << " " << setfill(' ') << setw(largestIng) << left << printIt->getName();
			cout << " | ";
			cout << printIt->getAmount() << endl;
			++printIt;
		}

		cout << endl;
		// END PRINT FORMATTING

		cout << " How many " << EOWInvIt->getName() << " are in stock at the end of the week (rounded down, to the nearest whole)?" << endl;

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
				cout << "\n *** END OF WEEK INVENTORY *** \n" << endl;
				cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
				cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
				cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
				printIt = EOWInventory.begin();
				while (printIt != EOWInvIt)
				{
					cout << " " << setfill(' ') << setw(largestIng) << left << printIt->getName();
					cout << " | ";
					cout << printIt->getAmount() << endl;
					++printIt;
				}
				cout << endl;
				cout << " Invalid response. How many " << EOWInvIt->getName() << " are in stock at the end of the week (rounded down, to the nearest whole)?" << endl;
			}
		}

		int amount = stoi(line);
		EOWInvIt->setAmount(amount);

		++EOWInvIt;
	}
	system("CLS");

	// PRINTING FORMATTING
	cout << "\n *** END OF WEEK INVENTORY *** \n" << endl;
	cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
	cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
	cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
	for (Ingredient &i : EOWInventory)
	{
		cout << " " << setfill(' ') << setw(largestIng) << left << i.getName();
		cout << " | ";
		cout << i.getAmount() << endl;
	}
	cout << endl;
	cout << " ";
	system("Pause");
	// END PRINTING FORMATTING
	writeIngredientType(BOWInventory, editingDate.beginWeek(), 0);
	writeIngredientType(EOWInventory, editingDate.beginWeek(), 1);


	// CALCULATING WASTE
	list<Ingredient> ideal = BOWInventory;
	list<Ingredient> waste = EOWInventory;
	list<MenuItem> sales = readMenuItemType("#4" + editingDate.beginWeek().toDigit());
	list<MenuItem> menu = readMenuItems();

	for (MenuItem &m : menu)
	{
		for (MenuItem &s : sales)
		{
			if (m == s)
				s.setIngredients(m.getIngredients());
		}
	}

	for (MenuItem &s : sales)
	{
		for (Ingredient &i : s.getIngredients())
		{
			for (Ingredient &uI : ingredientsUsed)
				if (uI == i)
					uI.setAmount(uI.getAmount() + (i.getAmount() * s.getAmountSold()));
		}

	}
	
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
	list<Ingredient> order = EOWInventory;

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

void EditSingleWeekInventoryHistory::menu()
{
	nextDisplay = new SingleWeekInventoryHistory();
	nextDisplay->setContent(content);
}

EditSingleWeekInventoryHistory::~EditSingleWeekInventoryHistory()
{

}