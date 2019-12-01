#ifndef SINGLE_WEEK_INVENTORY_HISTORY_H
#define SINGLE_WEEK_INVENTORY_HISTORY_H

#include "Display.h"

class SingleWeekInventoryHistory : public Display
{
public:
	// Constructors
	SingleWeekInventoryHistory();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~SingleWeekInventoryHistory();
private:
	string dateToShow;
};



#endif