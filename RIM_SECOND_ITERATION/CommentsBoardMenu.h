#ifndef COMMENTS_BOARD_MENU_H
#define COMMENTS_BOARD_MENU_H

#include "Display.h"

class CommentsBoardMenu : public Display
{
public:
	// Constructors
	CommentsBoardMenu();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~CommentsBoardMenu();
private:
};


#endif