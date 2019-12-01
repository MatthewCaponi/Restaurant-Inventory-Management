#include "CurrentDatabase.h"
#include "CurrentDatabaseMenu.h"
#include "Ingredient.h"
#include "MenuItem.h"
#include "DataIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
CurrentDatabase::CurrentDatabase()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void CurrentDatabase::setup()
{

}

void CurrentDatabase::run()
{
	list<Ingredient> BOWInventory = readIngredientType("#0" + Date().beginWeek().toDigit()), EOWInventory = readIngredientType("#1" + Date().beginWeek().toDigit());
	list<MenuItem> sales = readMenuItemType("#4" + Date().beginWeek().toDigit());

	if (BOWInventory.empty() && EOWInventory.empty())
	{
		list<Ingredient> ingredients = readIngredients();
		list<MenuItem> menu = readMenuItems();
		BOWInventory = ingredients, EOWInventory = ingredients;
		list<Ingredient> ingredientsUsed = ingredients;
		list<MenuItem> menuSold = menu;

		int largestIng = static_cast<int>(BOWInventory.begin()->getName().size());
		for (Ingredient &i : BOWInventory)
			largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;

		list<Ingredient>::iterator BOWInvIt = BOWInventory.begin();
		while (BOWInvIt != BOWInventory.end())
		{
			system("CLS");

			// PRINT FORMATTING
			cout << "\n *** BEGINNING OF WEEK INVENTORY *** " << endl;
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
					cout << "\n *** BEGINNING OF WEEK INVENTORY *** " << endl;
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
		cout << "\n *** BEGINNING OF WEEK INVENTORY *** " << endl;
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
		// END PRINTING FORMATTING

		int largestMenu = static_cast<int>(menuSold.begin()->getName().size());
		for (MenuItem &m : menuSold)
			largestMenu = (static_cast<int>(m.getName().size()) > largestMenu) ? static_cast<int>(m.getName().size()) : largestMenu;

		list<MenuItem>::iterator menuSoldIt = menuSold.begin();
		while (menuSoldIt != menuSold.end())
		{
			system("CLS");

			// PRINT FORMATTING
			cout << "\n *** MENU ITEMS SOLD *** " << endl;
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
					cout << "\n *** MENU ITEMS SOLD *** " << endl;
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
		cout << "\n *** MENU ITEMS SOLD *** " << endl;
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

		// END PRINT FORMATTING
		list<Ingredient>::iterator EOWInvIt = EOWInventory.begin();
		while (EOWInvIt != EOWInventory.end())
		{
			system("CLS");

			// PRINT FORMATTING
			cout << "\n *** END OF WEEK INVENTORY *** " << endl;
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
					cout << "\n *** END OF WEEK INVENTORY *** " << endl;
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
		cout << "\n *** END OF WEEK INVENTORY *** " << endl;
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
		writeIngredientType(BOWInventory, Date().beginWeek(), 0);
		writeIngredientType(EOWInventory, Date().beginWeek(), 1);
		writeMenuItemType(menuSold, Date().beginWeek(), 4);


		// CALCULATING WASTE
		list<Ingredient> ideal = BOWInventory;
		list<Ingredient> waste = EOWInventory;
		list<MenuItem> sales = menuSold;

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

		writeIngredientType(waste, Date().beginWeek(), 2);

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

		writeIngredientType(order, Date().beginWeek(), 3);
	}
	else
	{
		cout << "\n *** CURRENT INVENTORY *** \n" << endl;

		int largestIng = static_cast<int>(BOWInventory.begin()->getName().size());
		for (Ingredient &i : BOWInventory)
			largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;
		cout << " *** BEGINNING OF WEEK INVENTORY REPORT : WEEK OF " << Date().beginWeek() << " *** " << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		for (Ingredient &i : BOWInventory)
		{
			cout << " " << setfill(' ') << setw(largestIng) << left << i.getName();
			cout << " | ";
			cout << i.getAmount() << endl;
		}
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;

		int largestMenu = static_cast<int>(sales.begin()->getName().size());
		for (MenuItem &m : sales)
			largestMenu = (static_cast<int>(m.getName().size()) > largestMenu) ? static_cast<int>(m.getName().size()) : largestMenu;
		cout << "\n *** SALES REPORT : WEEK OF " << Date().beginWeek() << " *** " << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		cout << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | amount sold " << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		double total = 0;
		for (MenuItem &m : sales)
		{
			total += m.getAmountSold() * m.getPrice();
			cout << " " << setfill(' ') << setw(largestMenu) << left << m.getName();
			cout << " | ";
			cout << m.getAmountSold() << endl;
		}
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		cout << " Sales total: $" << fixed << setprecision(2) << total << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		cout << "\n *** END OF WEEK INVENTORY REPORT : WEEK OF " << Date().beginWeek() << " *** " << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		for (Ingredient &i : EOWInventory)
		{
			cout << " " << setfill(' ') << setw(largestIng) << left << i.getName();
			cout << " | ";
			cout << i.getAmount() << endl;
		}
		cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		cout << endl;

		cout << " Would you like to replace the current data? (Y/N)" << endl;
		bool answered = false, replace = false;
		while (!answered)
		{
			string line;
			cout << " ";
			getline(cin, line);
			if (static_cast<int>(line.size()) != 1)
			{
				system("CLS");
				cout << "\n *** CURRENT INVENTORY *** \n";
				cout << " That's an invalid response. Please try again." << endl;
				cout << " Data seems to be filled already. Would you like to replace the current data? (Y/N)" << endl;
			}
			else
			{
				char c = line[0];
				if (toupper(c) == 'Y')
				{
					answered = true;
					replace = true;
				}
				else if (toupper(c) == 'N')
				{
					answered = true;
				}
				else
				{
					system("CLS");
					cout << "\n *** CURRENT INVENTORY *** \n";
					cout << " That's an invalid response. Please try again." << endl;
					cout << " Data seems to be filled already. Would you like to replace the current data? (Y/N)" << endl;
				}
			}		
		}
		
		if (replace)
		{
			list<Ingredient> ingredients = readIngredients();
			list<MenuItem> menu = readMenuItems();
			BOWInventory = ingredients, EOWInventory = ingredients;
			list<Ingredient> ingredientsUsed = ingredients;
			list<MenuItem> menuSold = menu;

			int largestIng = static_cast<int>(BOWInventory.begin()->getName().size());
			for (Ingredient &i : BOWInventory)
				largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;

			list<Ingredient>::iterator BOWInvIt = BOWInventory.begin();
			while (BOWInvIt != BOWInventory.end())
			{
				system("CLS");

				// PRINT FORMATTING
				cout << "\n *** BEGINNING OF WEEK INVENTORY *** " << endl;
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
						cout << "\n *** BEGINNING OF WEEK INVENTORY *** " << endl;
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
			cout << "\n *** BEGINNING OF WEEK INVENTORY *** " << endl;
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
			// END PRINTING FORMATTING

			int largestMenu = static_cast<int>(menuSold.begin()->getName().size());
			for (MenuItem &m : menuSold)
				largestMenu = (static_cast<int>(m.getName().size()) > largestMenu) ? static_cast<int>(m.getName().size()) : largestMenu;

			list<MenuItem>::iterator menuSoldIt = menuSold.begin();
			while (menuSoldIt != menuSold.end())
			{
				system("CLS");

				// PRINT FORMATTING
				cout << "\n *** MENU ITEMS SOLD *** " << endl;
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
						cout << "\n *** MENU ITEMS SOLD *** " << endl;
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
			cout << "\n *** MENU ITEMS SOLD *** " << endl;
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

			// END PRINT FORMATTING
			list<Ingredient>::iterator EOWInvIt = EOWInventory.begin();
			while (EOWInvIt != EOWInventory.end())
			{
				system("CLS");

				// PRINT FORMATTING
				cout << "\n *** END OF WEEK INVENTORY *** " << endl;
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
						cout << "\n *** END OF WEEK INVENTORY *** " << endl;
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
			cout << "\n *** END OF WEEK INVENTORY *** " << endl;
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
			writeIngredientType(BOWInventory, Date().beginWeek(), 0);
			writeIngredientType(EOWInventory, Date().beginWeek(), 1);
			writeMenuItemType(menuSold, Date().beginWeek(), 4);


			// CALCULATING WASTE
			list<Ingredient> ideal = BOWInventory;
			list<Ingredient> waste = EOWInventory;
			list<MenuItem> sales = menuSold;

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

			writeIngredientType(waste, Date().beginWeek(), 2);

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
			writeIngredientType(order, Date().beginWeek(), 3);
		}
	}
}

void CurrentDatabase::menu()
{
	nextDisplay = new CurrentDatabaseMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
CurrentDatabase::~CurrentDatabase() {}