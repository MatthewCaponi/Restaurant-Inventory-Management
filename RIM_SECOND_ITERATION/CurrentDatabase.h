#ifndef CURRENT_DATABASE_H
#define CURRENT_DATABASE_H

#include "Display.h"

class CurrentDatabase : public Display
{
public:
	// Constructors
	CurrentDatabase();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~CurrentDatabase();

private:
};

#endif