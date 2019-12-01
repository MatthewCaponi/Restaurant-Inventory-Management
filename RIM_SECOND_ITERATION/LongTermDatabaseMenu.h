#ifndef LONG_TERM_DATABASE_MENU_H
#define LONG_TERM_DATABASE_MENU_H

#include "Display.h"

class LongTermDatabaseMenu : public Display
{
public:
	// Constructors
	LongTermDatabaseMenu();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~LongTermDatabaseMenu();
private:
};

#endif
