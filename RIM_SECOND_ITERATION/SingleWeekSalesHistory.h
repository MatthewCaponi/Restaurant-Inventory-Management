#ifndef SINGLE_WEEK_SALES_HISTORY_H
#define SINGLE_WEEK_SALES_HISTORY_H

#include "Display.h"

class SingleWeekSalesHistory : public Display
{
public:
	// Constructors
	SingleWeekSalesHistory();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~SingleWeekSalesHistory();
private:
	string dateToShow;
};



#endif