#ifndef ORDER_REPORT_H
#define ORDER_REPORT_H

#include "Display.h"

class OrderReport : public Display
{
public:
	// Constructors
	OrderReport();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~OrderReport();

private:
};

#endif
