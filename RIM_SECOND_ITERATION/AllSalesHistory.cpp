#include "AllSalesHistory.h"
#include "SalesDatabase.h"
#include "DataIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
AllSalesHistory::AllSalesHistory()
{

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void AllSalesHistory::setup()
{

}

void AllSalesHistory::run()
{
	cout << endl;
	cout << " *** SALES RECORDS FROM THE PAST YEAR *** \n" << endl;
	string idSales;
	bool noRecords = true;
	list<MenuItem> sales;
	list<MenuItem> averageSales = readMenuItems();
	int counter = 0, largestMenu = 0;
	list<MenuItem> totalSales = readMenuItems();
	Date now;
	Date d = now - 365;
	Date earliestDate;
	while (d.beginWeek() < now.beginWeek())
	{
		idSales = "#4" + d.beginWeek().toDigit();
		sales = readMenuItemType(idSales);

		if (!sales.empty())
		{
			if (noRecords)
				earliestDate = d.beginWeek();
			noRecords = false;

			largestMenu = static_cast<int>(sales.begin()->getName().size());
			for (MenuItem &m : sales)
				largestMenu = (static_cast<int>(m.getName().size()) > largestMenu) ? static_cast<int>(m.getName().size()) : largestMenu;
			cout << " *** SALES REPORT : WEEK OF " << d.beginWeek() << " *** " << endl;
			cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
			cout << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | amount sold " << endl;
			cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
			double total = 0;
			for (MenuItem &m : sales)
			{
				total += m.getAmountSold() * m.getPrice();
				cout << " " << setfill(' ') << setw(largestMenu) << left << m.getName();
				cout << " | ";
				cout << m.getAmountSold() << endl;
				for (MenuItem &mTotal : totalSales)
				{
					if (m.getName() == mTotal.getName())
						mTotal.setAmountSold(mTotal.getAmountSold() + m.getAmountSold());
				}
			}
			cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
			cout << " Sales total: $" << fixed << setprecision(2) << total << endl;
			cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
			++counter;
		}
		d = d + 7;
	}

	if (noRecords)
		cout << "\n No records found!" << endl;
	else
	{
		cout << " *** AVERAGE SALES REPORT STARTING FROM WEEK OF " << earliestDate.beginWeek() << " *** " << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		cout << " " << setfill(' ') << setw(largestMenu) << left << "menu item" << " | average amount sold " << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		double totalAverage = 0;
		for (MenuItem &mTotal : totalSales)
		{
			cout << " " << setfill(' ') << setw(largestMenu) << left << mTotal.getName();
			cout << " | ";
			double averageSold = static_cast<double>(mTotal.getAmountSold()) / static_cast<double>(counter);
			cout << fixed << setprecision(2) << averageSold << " per week" << endl;
			totalAverage += averageSold * mTotal.getPrice();
		}
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
		cout << " Average sales: $" << fixed << setprecision(2) << totalAverage << endl;
		cout << " " << setfill('-') << setw(largestMenu) << "-" << "---------------" << endl;
	}

	cout << " ";
	system("Pause");
}

void AllSalesHistory::menu()
{
	nextDisplay = new SalesDatabase();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
AllSalesHistory::~AllSalesHistory()
{

}