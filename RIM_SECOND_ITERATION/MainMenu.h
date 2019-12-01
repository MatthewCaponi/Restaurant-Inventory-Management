#ifndef MAINMENU_H
#define MAINMENU_H
#include "Display.h"

class MainMenu : public Display
{
public:
	// Constructors
	MainMenu();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~MainMenu();
private:
};
#endif