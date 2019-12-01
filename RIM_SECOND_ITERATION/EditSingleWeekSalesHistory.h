#include "Display.h"

class EditSingleWeekSalesHistory : public Display
{
public:
	// Constructors
	EditSingleWeekSalesHistory(const string& newDateToEdit);
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~EditSingleWeekSalesHistory();

private:
	string dateToEdit;
};