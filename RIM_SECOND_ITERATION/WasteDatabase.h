#ifndef WASTE_DATABASE_H
#define WASTE_DATABASE_H
#include "Display.h"

class WasteDatabase : public Display
{
public:
	// Constructors
	WasteDatabase();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~WasteDatabase();
private:
};



#endif