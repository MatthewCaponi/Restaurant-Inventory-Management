#ifndef INVENTORY_DATABASE_H
#define INVENTORY_DATABASE_H

#include "Display.h"

class InventoryDatabase : public Display
{
public:
	// Constructors
	InventoryDatabase();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~InventoryDatabase();
private:
};

#endif