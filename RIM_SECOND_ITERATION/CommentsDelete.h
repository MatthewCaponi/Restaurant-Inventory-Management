#ifndef COMMENTS_DELETE_H
#define COMMENTS_DELETE_H

#include "Display.h"

class CommentsDelete : public Display
{
public:
	// Constructors
	CommentsDelete();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~CommentsDelete();
private:
};


#endif