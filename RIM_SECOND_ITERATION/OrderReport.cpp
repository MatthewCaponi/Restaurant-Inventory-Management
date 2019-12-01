#include "OrderReport.h"
#include "CurrentDatabaseMenu.h"
#include "DataIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
OrderReport::OrderReport()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void OrderReport::setup()
{

}

void OrderReport::run()
{
	list<Ingredient> order = readIngredientType("#3" + Date().beginWeek().toDigit());

	if (order.empty())
	{
		cout << "\n *** ORDER REPORT *** \n" << endl;
		cout << "Sorry! Insufficient amount of data. Please enter current week's data." << endl;
	}
	else
	{

		int largestNameSize = static_cast<int>(order.begin()->getName().size());
		for (Ingredient &w : order)
			largestNameSize = (static_cast<int>(w.getName().size()) > largestNameSize) ? static_cast<int>(w.getName().size()) : largestNameSize;
		int largestAmount = order.begin()->getAmount();
		for (Ingredient &w : order)
			largestAmount = (w.getAmount() > largestAmount) ? w.getAmount() : largestAmount;
		int largestAmountSize = (static_cast<int>(floor(log10(largestAmount))) > 6) ? static_cast<int>(floor(log10(largestAmount))) : 6;
		double totalAmount = 0.0;
		cout << "\n *** ORDER REPORT *** \n" << endl;
		cout << " " << setfill('-') << right << setw(largestNameSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << "--" << endl;
		cout << " " << setfill(' ') << setw(largestNameSize) << left << "ingredient";
		cout << " | ";
		cout << setfill(' ') << setw(largestAmountSize) << left << "amount";
		cout << " | subcost " << endl;
		cout << " " << setfill('-') << right << setw(largestNameSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << setw(largestAmountSize) << "-" << "--" << endl;
		for (Ingredient &w : order)
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

void OrderReport::menu()
{
	nextDisplay = new CurrentDatabaseMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
OrderReport::~OrderReport() {}