#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <iomanip>
#include <iostream>
#include <list>
#include "Ingredient.h"

using namespace std;

class MenuItem : public Data
{
public:
	// Constructors
	MenuItem();
	MenuItem(const string &newName, int newAmountSold);
	MenuItem(const string &newName, double newPrice, const list<Ingredient> &newIngredients);
	MenuItem(const string &newName, double newPrice, int newAmountSold, const list<Ingredient> &newIngredients);
	// Setters
	void setName(const string &newName);
	void setPrice(double newPrice);
	void setAmountSold(int newAmountSold);
	void setIngredients(const list<Ingredient> &ingredients);
	// Getters
	string getName() const;
	double getPrice() const;
	int getAmountSold() const;
	list<Ingredient> getIngredients() const;
	// Helpers
	bool operator==(const MenuItem &other) const;
	list<Ingredient> getAmountIngredientsUsed() const;
	ostream& print(ostream& out) const;
	friend ostream& operator<<(ostream& out, const MenuItem &mi);
	// Destructor
	~MenuItem();
private:
	string name;
	double price;
	int amountSold;
	list<Ingredient> ingredients;
};

#endif
