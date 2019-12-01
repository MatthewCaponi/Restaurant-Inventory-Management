#ifndef SALES_DATABASE_H
#define SALES_DATABASE_H

#include "Display.h"

class SalesDatabase : public Display
{
public:
	// Constructors
	SalesDatabase();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~SalesDatabase();
private:
};



#endif
