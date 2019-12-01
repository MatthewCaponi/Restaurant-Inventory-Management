#include "Display.h"

class EditSingleWeekInventoryHistory : public Display
{
public:
	// Constructors
	EditSingleWeekInventoryHistory(const string& newDateToEdit);
	// Helpers
	void setup();
	void run();
	void menu();
	// Destructors
	~EditSingleWeekInventoryHistory();

private:
	string dateToEdit;
};