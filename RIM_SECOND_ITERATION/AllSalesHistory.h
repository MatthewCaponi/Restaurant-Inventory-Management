#pragma once
#ifndef ALL_SALES_HISTORY_H
#define ALL_SALES_HISTORY_H

#include "Display.h"

class AllSalesHistory : public Display
{
public:
	// Constructors
	AllSalesHistory();
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~AllSalesHistory();
private:
};



#endif
