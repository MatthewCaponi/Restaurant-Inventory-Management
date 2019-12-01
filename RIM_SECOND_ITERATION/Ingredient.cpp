#include "Ingredient.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors 
Ingredient::Ingredient() : Data(INGREDIENT)
{
	baseCostPerUnit = 0;
	amount = 0;
	baseExpiration = 0;
}

Ingredient::Ingredient(const string &newName) : Data(INGREDIENT)
{
	baseCostPerUnit = 0;
	amount = 0;
	baseExpiration = 0;
	name = newName;
}

Ingredient::Ingredient(const string &newName, double newBaseCostPerUnit) : Data(INGREDIENT)
{
	amount = 0;
	baseExpiration = 0;
	name = newName;
	baseCostPerUnit = newBaseCostPerUnit;
}

Ingredient::Ingredient(const string &newName, int newAmount) : Data(INGREDIENT)
{
	baseCostPerUnit = 0;
	baseExpiration = 0;
	name = newName;
	amount = newAmount;
}

Ingredient::Ingredient(const string &newName, double newBaseCostPerUnit, int newBaseExpiration) : Data(INGREDIENT)
{
	name = newName;
	baseCostPerUnit = newBaseCostPerUnit;
	baseExpiration = newBaseExpiration;
	amount = 0;
}

Ingredient::Ingredient(const string &newName, double newBaseCostPerUnit, int newBaseExpiration, int newAmount) : Data(INGREDIENT)
{
	name = newName;
	baseCostPerUnit = newBaseCostPerUnit;
	baseExpiration = newBaseExpiration;
	amount = newAmount;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setters
void Ingredient::setName(const string &newName)
{
	name = newName;
}

void Ingredient::setBaseCostPerUnit(double newBaseCostPerUnit)
{
	baseCostPerUnit = newBaseCostPerUnit;
}

void Ingredient::setBaseExpiration(int newBaseExpiration)
{
	baseExpiration = newBaseExpiration;
}

void Ingredient::setAmount(int newAmount)
{
	amount = newAmount;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getters
string Ingredient::getName() const
{
	return name;
}

double Ingredient::getBaseCostPerUnit() const
{
	return baseCostPerUnit;
}

int Ingredient::getBaseExpiration() const
{
	return baseExpiration;
}

int Ingredient::getAmount() const
{
	return amount;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
bool Ingredient::operator==(const Ingredient &i)
{
	return name == i.name;
}

ostream& Ingredient::print(ostream& out) const
{
	out << name << " | shelf life: " << baseExpiration << " days | base price: $" << fixed << setprecision(2) << baseCostPerUnit;
	return out;
}

ostream& operator<<(ostream &out, const Ingredient &i)
{
	i.print(out);
	return out;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Deconstructors
Ingredient::~Ingredient() {}