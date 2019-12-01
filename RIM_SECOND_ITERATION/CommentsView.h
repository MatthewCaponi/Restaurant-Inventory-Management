#ifndef COMMENTS_VIEW_H
#define COMMENTS_VIEW_H

#include "Display.h"

class CommentsView : public Display
{
public:
	// Constructors
	CommentsView();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~CommentsView();
private:
};


#endif