#ifndef RESTAURANT_MENU_AND_INVENTORY_VIEW_H
#define RESTAURANT_MENU_AND_INVENTORY_VIEW_H

#include "Display.h"

class RestaurantMenuAndInventoryView : public Display
{
public:
	// Constructors
	RestaurantMenuAndInventoryView();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~RestaurantMenuAndInventoryView();
private:
};


#endif