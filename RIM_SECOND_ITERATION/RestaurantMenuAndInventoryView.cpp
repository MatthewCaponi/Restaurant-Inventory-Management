#include "RestaurantMenuAndInventoryView.h"
#include "MainMenu.h"
#include "DataIO.h"
#include "MenuItem.h"
#include "Ingredient.h"
#include <list>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
RestaurantMenuAndInventoryView::RestaurantMenuAndInventoryView()
{
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void RestaurantMenuAndInventoryView::setup()
{

}

void RestaurantMenuAndInventoryView::run()
{
	list<Ingredient> inventory = readIngredients();
	list<MenuItem> menu = readMenuItems();

	int largestMenu = static_cast<int>(menu.begin()->getName().size());
	for (MenuItem &m : menu)
		largestMenu = (static_cast<int>(m.getName().size()) > largestMenu) ? static_cast<int>(m.getName().size()) : largestMenu;
	cout << "\n *** RESTAURANT MENU *** " << endl;
	cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
	cout << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | price " << endl;
	cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;

	for (MenuItem &m : menu)
	{
		cout << " " << setfill(' ') << setw(largestMenu) << left << m.getName();
		cout << " | $";
		cout << fixed << setprecision(2) << m.getPrice() << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		cout << "    INGREDIENTS: "<< endl;

		list<Ingredient> ingredients = m.getIngredients();

		int largestIng = static_cast<int>(ingredients.begin()->getName().size());
		for (Ingredient &i : ingredients)
			largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;
		cout << "    " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		cout << "    " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
		cout << "    " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		for (Ingredient &i : ingredients)
		{
			cout << "    " << setfill(' ') << setw(largestIng) << left << i.getName();
			cout << " | ";
			cout << i.getAmount() << endl;
		}
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
	}
	list<Ingredient> ingredients = readIngredients();
	int largestIng = static_cast<int>(ingredients.begin()->getName().size());
	cout << "\n *** LIST OF INGREDIENTS *** " << endl;
	for (Ingredient &i : ingredients)
		largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;
	cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
	cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | cost " << endl;
	cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
	for (Ingredient &i : ingredients)
	{
		cout << " " << setfill(' ') << setw(largestIng) << left << i.getName();
		cout << " | $";
		cout << fixed << setprecision(2) << i.getBaseCostPerUnit() << endl;
	}
	cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;

	cout << " ";
	system("Pause");
}

void RestaurantMenuAndInventoryView::menu()
{
	nextDisplay = new MainMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
RestaurantMenuAndInventoryView::~RestaurantMenuAndInventoryView() {}