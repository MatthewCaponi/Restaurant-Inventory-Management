#ifndef SHIPMENTGROUP_H
#define SHIPMENTGROUP_H

#include <string>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Ingredient.h"
#include "Date.h"

using namespace std;

class ShipmentGroup : public Data
{
public:
	// Constructors
	ShipmentGroup();
	// Setters
	void setIngredient(const Ingredient &newIngredient);
	void setAmount(int newAmount);
	void setSubCost(double newSubCost);
	void setEstimatedExpiration(const Date &newEstimatedExpiration);
	// Getters
	Ingredient getIngredient() const;
	int getAmount() const;
	double getSubCost() const; 
	Date getEstimatedExpiration() const;
	// Helpers
	ostream& print(ostream& out) const;
	friend ostream& operator<<(ostream& out, const ShipmentGroup &sg);
	// Destructors
	~ShipmentGroup();
private:
	Ingredient ingredient;
	int amount;
	double subCost;
	Date estimatedExpiration;
};


#endif
