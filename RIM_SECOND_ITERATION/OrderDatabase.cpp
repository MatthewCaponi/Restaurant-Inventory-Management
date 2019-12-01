#include "OrderDatabase.h"
#include "LongTermDatabaseMenu.h"
#include "DataIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
OrderDatabase::OrderDatabase()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void OrderDatabase::setup()
{

}

void OrderDatabase::run()
{
	cout << endl;
	cout << " *** ORDER RECORDS FROM THE PAST YEAR *** " << endl;
	string idOrder;
	bool noRecords = true;
	list<Ingredient> order;
	Date now;
	Date d = now - 365;
	while (d.beginWeek() < now.beginWeek())
	{
		idOrder = "#3" + d.beginWeek().toDigit();
		order = readIngredientType(idOrder);

		if (!order.empty())
		{
			noRecords = false;

			int largestNameSize = static_cast<int>(order.begin()->getName().size());
			for (Ingredient &o : order)
				largestNameSize = (static_cast<int>(o.getName().size()) > largestNameSize) ? static_cast<int>(o.getName().size()) : largestNameSize;
			int largestAmount = order.begin()->getAmount();
			for (Ingredient &o : order)
				largestAmount = (o.getAmount() > largestAmount) ? o.getAmount() : largestAmount;
			int largestAmountSize = (static_cast<int>(floor(log10(largestAmount))) > 6) ? static_cast<int>(floor(log10(largestAmount))) : 6;
			double totalAmount = 0.0;
			cout << "\n *** ORDER REPORT : WEEK OF " << d.beginWeek() << " *** \n" << endl;
			cout << " " << setfill(' ') << setw(largestNameSize) << left << "ingredient";
			cout << " | ";
			cout << setfill(' ') << setw(largestAmountSize) << left << "amount";
			cout << " | subcost " << endl << endl;
			for (Ingredient &o : order)
			{
				cout << " " << setfill(' ') << setw(largestNameSize) << left << o.getName();
				cout << " | ";
				cout << setfill(' ') << setw(largestAmountSize) << left << o.getAmount();
				cout << " | $" << fixed << setprecision(2) << o.getAmount() * o.getBaseCostPerUnit() << endl;
				totalAmount += o.getAmount() * o.getBaseCostPerUnit();
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

void OrderDatabase::menu()
{
	nextDisplay = new LongTermDatabaseMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
OrderDatabase::~OrderDatabase()
{

}