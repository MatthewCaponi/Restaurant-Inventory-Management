#include "WasteReport.h"
#include "CurrentDatabaseMenu.h"
#include "DataIO.h"
#include <iostream>
#include <math.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
WasteReport::WasteReport()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void WasteReport::setup()
{

}

void WasteReport::run()
{
	list<Ingredient> waste = readIngredientType("#2" + Date().beginWeek().toDigit());

	if (waste.empty())
	{
		cout << "\n *** WASTE REPORT *** \n" << endl;
		cout << " Sorry! Insufficient amount of data. Please enter current week's data." << endl;
	}
	else
	{

		int largestNameSize = static_cast<int>(waste.begin()->getName().size());
		for (Ingredient &w : waste)
			largestNameSize = (static_cast<int>(w.getName().size()) > largestNameSize) ? static_cast<int>(w.getName().size()) : largestNameSize;
		int largestAmount = waste.begin()->getAmount();
		for (Ingredient &w : waste)
			largestAmount = (w.getAmount() > largestAmount) ? w.getAmount() : largestAmount;
		int largestAmountSize = (static_cast<int>(floor(log10(largestAmount))) > 6) ? static_cast<int>(floor(log10(largestAmount))) : 6;
		double totalAmount = 0.0;
		cout << "\n *** WASTE REPORT *** \n" << endl;
		cout << " " << setfill('-') << right << setw(largestNameSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << "--" << endl;
		cout << " " << setfill(' ') << setw(largestNameSize) << left << "ingredient";
		cout << " | ";
		cout << setfill(' ') << setw(largestAmountSize) << left << "amount";
		cout << " | subcost " << endl;
		cout << " " << setfill('-') << right << setw(largestNameSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << "--" << endl;
		for (Ingredient &w : waste)
		{
			cout << " " << setfill(' ') << setw(largestNameSize) << left << w.getName();
			cout << " | ";
			cout << setfill(' ') << setw(largestAmountSize) << left << w.getAmount();
			cout << " | $" << fixed << setprecision(2) << w.getAmount() * w.getBaseCostPerUnit() << endl;
			totalAmount += w.getAmount() * w.getBaseCostPerUnit();
		}
		cout << " " << setfill('-') << right << setw(largestNameSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << "--" << endl;
		cout << " Total cost: $" << fixed << setprecision(2) << totalAmount << endl;
	}
	cout << endl;
	cout << " ";
	system("Pause");
}

void WasteReport::menu()
{
	nextDisplay = new CurrentDatabaseMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
WasteReport::~WasteReport() {}