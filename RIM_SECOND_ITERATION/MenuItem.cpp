#include "MenuItem.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
MenuItem::MenuItem() : Data(MENU_ITEM)
{
	price = 0;
	amountSold = 0;
}

MenuItem::MenuItem(const string& newName, int newAmountSold) : Data(MENU_ITEM)
{
	name = newName;
	amountSold = newAmountSold;
	price = 0;
}

MenuItem::MenuItem(const string &newName, double newPrice, const list<Ingredient> &newIngredients) : Data(MENU_ITEM)
{
	amountSold = 0;
	name = newName;
	price = newPrice;
	ingredients = newIngredients;

}

MenuItem::MenuItem(const string &newName, double newPrice, int newAmountSold, const list<Ingredient> &newIngredients) : Data(MENU_ITEM)
{
	name = newName;
	price = newPrice;
	amountSold = newAmountSold;
	ingredients = newIngredients;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setters
void MenuItem::setName(const string &newName)
{
	name = newName;
}

void MenuItem::setPrice(double newPrice)
{
	price = newPrice;
}

void MenuItem::setAmountSold(int newAmountSold)
{
	amountSold = newAmountSold;
}

void MenuItem::setIngredients(const list<Ingredient> &newIngredients)
{
	ingredients = newIngredients;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getters
string MenuItem::getName() const
{
	return name;
}

double MenuItem::getPrice() const
{
	return price;
}

int MenuItem::getAmountSold() const
{
	return amountSold;
}

list<Ingredient> MenuItem::getIngredients() const
{
	return ingredients;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers

bool MenuItem::operator==(const MenuItem &other) const
{
	return name == other.name;
}

list<Ingredient> MenuItem::getAmountIngredientsUsed() const
{
	list<Ingredient> ingredientsUsed = ingredients;
	for (Ingredient &iUsed : ingredientsUsed)
	{
		for (const Ingredient &i : ingredients)
		{
			if (iUsed == i)
				iUsed.setAmount(amountSold * i.getAmount());
		}
	}

	return ingredientsUsed;
}

ostream& MenuItem::print(ostream &out) const
{
	out << fixed << setprecision(2);
	out << name << " | price: $" << price << " | amount sold: " << amountSold << endl;

	int counter = 1;
	out << "        *** INGREDIENTS ***" << endl;
	out << "     ingredient name | amount used " << endl;
	for (auto &i : ingredients)
	{
		out << "  " << counter << ": ";
		out << setfill(' ') << setw(15) << left << i.getName();
		out << " | ";
		out << setfill(' ') << left << i.getAmount();
		if (counter != ingredients.size())
			cout << endl;
		++counter;
	}
	return out;
}

ostream& operator<<(ostream& out, const MenuItem &mi)
{
	mi.print(out);
	return out;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
MenuItem::~MenuItem() {}