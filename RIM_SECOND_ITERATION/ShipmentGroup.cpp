#include "ShipmentGroup.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
ShipmentGroup::ShipmentGroup() : Data(SHIPMENT_GROUP)
{
	subCost = 0;
	amount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setters
void ShipmentGroup::setIngredient(const Ingredient &newIngredient)
{
	ingredient = newIngredient;
}

void ShipmentGroup::setAmount(int newAmount)
{
	amount = newAmount;
}

void ShipmentGroup::setSubCost(double newSubCost)
{
	subCost = newSubCost;
}

void ShipmentGroup::setEstimatedExpiration(const Date &newEstimatedExpiration)
{
	estimatedExpiration = newEstimatedExpiration;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getters
Ingredient ShipmentGroup::getIngredient() const
{
	return ingredient;
}

int ShipmentGroup::getAmount() const
{
	return amount;
}

double ShipmentGroup::getSubCost() const
{
	return subCost;
}

Date ShipmentGroup::getEstimatedExpiration() const
{
	return estimatedExpiration;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
ostream& ShipmentGroup::print(ostream &out) const
{
	out << fixed << setprecision(2);
	out << ingredient.getName() << " | amount: " << amount << " | subcost: $" << subCost << " | expires: " << estimatedExpiration;
	return out;
}

ostream& operator<<(ostream&out, const ShipmentGroup &sg)
{
	sg.print(out);
	return out;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Deconstructors
ShipmentGroup::~ShipmentGroup() {}