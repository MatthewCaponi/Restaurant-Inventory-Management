#ifndef WASTE_REPORT_H
#define WASTE_REPORT_H

#include "Display.h"

class WasteReport : public Display
{
public:
	// Constructors
	WasteReport();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~WasteReport();

private:
};

#endif
