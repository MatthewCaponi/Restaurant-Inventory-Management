#ifndef ORDER_DATABASE_H
#define ORDER_DATBASE_H
#include "Display.h"

class OrderDatabase : public Display
{
public:
	// Constructors
	OrderDatabase();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~OrderDatabase();
private:
};




#endif