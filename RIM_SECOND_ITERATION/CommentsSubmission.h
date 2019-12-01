#ifndef COMMENTS_SUBMISSION_H
#define COMMENTS_SUBMISSION_H

#include "Display.h"

class CommentsSubmission : public Display
{
public:
	// Constructors
	CommentsSubmission();
	// Helpers
	void setup();
	void run();
	void menu();
	void showMenu();
	// Destructors
	~CommentsSubmission();
private:
};


#endif