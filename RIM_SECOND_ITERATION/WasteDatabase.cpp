#include "WasteDatabase.h"
#include "LongTermDatabaseMenu.h"
#include "DataIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
WasteDatabase::WasteDatabase()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void WasteDatabase::setup()
{

}

void WasteDatabase::run()
{
	cout << endl;
	cout << " *** WASTE RECORDS FROM THE PAST YEAR *** " << endl;
	string idWaste;
	bool noRecords = true;
	list<Ingredient> waste;
	Date now;
	Date d = now - 365;
	while (d.beginWeek() < now.beginWeek())
	{
		idWaste = "#2" + d.beginWeek().toDigit();
		waste = readIngredientType(idWaste);

		if (!waste.empty())
		{
			noRecords = false;

			int largestNameSize = static_cast<int>(waste.begin()->getName().size());
			for (Ingredient &w : waste)
				largestNameSize = (static_cast<int>(w.getName().size()) > largestNameSize) ? static_cast<int>(w.getName().size()) : largestNameSize;
			int largestAmount = waste.begin()->getAmount();
			for (Ingredient &w : waste)
				largestAmount = (w.getAmount() > largestAmount) ? w.getAmount() : largestAmount;
			int largestAmountSize = (static_cast<int>(floor(log10(largestAmount))) > 6) ? static_cast<int>(floor(log10(largestAmount))) : 6;
			double totalAmount = 0.0;
			cout << "\n *** WASTE REPORT : WEEK OF " << d.beginWeek() << " *** \n" << endl;
			cout << " " << setfill(' ') << setw(largestNameSize) << left << "ingredient";
			cout << " | ";
			cout << setfill(' ') << setw(largestAmountSize) << left << "amount";
			cout << " | subcost " << endl << endl;
			for (Ingredient &w : waste)
			{
				cout << " " << setfill(' ') << setw(largestNameSize) << left << w.getName();
				cout << " | ";
				cout << setfill(' ') << setw(largestAmountSize) << left << w.getAmount();
				cout << " | $" << fixed << setprecision(2) << w.getAmount() * w.getBaseCostPerUnit() << endl;
				totalAmount += w.getAmount() * w.getBaseCostPerUnit();
			}
			cout << endl;
			cout << " Total cost: $" << fixed << setprecision(2) << totalAmount << endl;
			cout << endl;
		}
		d = d + 7;
	}

	if (noRecords)
		cout << "\n No records found!" << endl;

	cout << " ";
	system("Pause");
}

void WasteDatabase::menu()
{
	nextDisplay = new LongTermDatabaseMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
WasteDatabase::~WasteDatabase()
{

}