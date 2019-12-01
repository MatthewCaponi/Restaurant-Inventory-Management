#include "AllInventoryHistory.h"
#include "InventoryDatabase.h"
#include "DataIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
AllInventoryHistory::AllInventoryHistory()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void AllInventoryHistory::setup()
{

}
void AllInventoryHistory::run()
{
	cout << endl;
	cout << " *** INVENTORY RECORDS FROM THE PAST YEAR *** \n" << endl;
	string idBOW, idEOW;
	bool noRecords = true;
	list<Ingredient> BOW, EOW;
	Date now;
	Date d = now - 365;
	while (d.beginWeek() < now.beginWeek())
	{
		idBOW = "#0" + d.beginWeek().toDigit();
		idEOW = "#1" + d.beginWeek().toDigit();
		BOW = readIngredientType(idBOW);
		EOW = readIngredientType(idEOW);

		if (!BOW.empty())
		{
			noRecords = false;
			int largestIng = static_cast<int>(BOW.begin()->getName().size());
			for (Ingredient &i : BOW)
				largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;
			cout << " *** BEGINNING OF WEEK INVENTORY REPORT : WEEK OF " << d.beginWeek() << " *** " << endl;
			cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
			cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
			cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
			for (Ingredient &i : BOW)
			{
				cout << " " << setfill(' ') << setw(largestIng) << left << i.getName();
				cout << " | ";
				cout << i.getAmount() << endl;
			}
			cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		}
		if (!EOW.empty())
		{
			noRecords = false;
			int largestIng = static_cast<int>(EOW.begin()->getName().size());
			for (Ingredient &i : EOW)
				largestIng = (static_cast<int>(i.getName().size()) > largestIng) ? static_cast<int>(i.getName().size()) : largestIng;
			cout << " *** END OF WEEK INVENTORY REPORT : WEEK OF " << d.beginWeek() << " *** " << endl;
			cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
			cout << " " << setfill(' ') << setw(largestIng) << left << "ingredient" << " | amount " << endl;
			cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
			for (Ingredient &i : EOW)
			{
				cout << " " << setfill(' ') << setw(largestIng) << left << i.getName();
				cout << " | ";
				cout << i.getAmount() << endl;
			}
			cout << " " << setfill('-') << setw(largestIng) << "-" << "----------" << endl;
		}
		d = d + 7;
	}

	if (noRecords)
		cout << "\n No records found!" << endl;
	cout << " ";
	system("Pause");
}
void AllInventoryHistory::menu()
{
	nextDisplay = new InventoryDatabase();
	nextDisplay->setIsEmployee(isEmployee);
}
// Destructors
AllInventoryHistory::~AllInventoryHistory() {}