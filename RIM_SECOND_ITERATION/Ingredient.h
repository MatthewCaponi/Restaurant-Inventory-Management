#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "Data.h"
#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>

using namespace std;

class Ingredient : public Data
{
public:
	// Constructors
	Ingredient();
	Ingredient(const string &newName);
	Ingredient(const string &newName, double newBaseCostPerUnit);
	Ingredient(const string &newName, int newAmount);
	Ingredient(const string &newName, double newBaseCostPerUnit, int newBaseExpiration);
	Ingredient(const string &newName, double newBaseCostPerUnit, int newBaseExpiration, int newAmount);
	// Setters
	void setName(const string &newName);
	void setBaseCostPerUnit(double newBaseCostPerUnit);
	void setBaseExpiration(int newBaseExpiration);
	void setAmount(int newAmount);
	// Getters
	string getName() const;
	double getBaseCostPerUnit() const;
	int getBaseExpiration() const;
	int getAmount() const;
	// Helpers
	bool operator ==(const Ingredient &i);
	friend ostream& operator<<(ostream &out, const Ingredient &i);
	ostream& print(ostream& out) const;
	// Deconstructors
	~Ingredient();
private:
	string name;
	double baseCostPerUnit;
	int baseExpiration;
	int amount;
};
#endif
