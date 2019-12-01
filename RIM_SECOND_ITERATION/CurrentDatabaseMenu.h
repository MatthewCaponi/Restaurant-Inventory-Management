#ifndef CURRENT_DATABASE_MENU
#define CURRENT_DATABASE_MENU

#include "Display.h"

class CurrentDatabaseMenu : public Display
{
public:
	// Constructors
	CurrentDatabaseMenu();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~CurrentDatabaseMenu();

private:
};

#endif
