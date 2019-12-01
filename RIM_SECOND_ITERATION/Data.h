#ifndef DATA_H
#define DATA_H

#define MENU_ITEM 1
#define INGREDIENT 2
#define SHIPMENT_GROUP 3
#define SHIPMENT 4
#define UNKNOWN 0
#include <iostream>

using namespace std;

class Data
{
public:
	// Constructors
	Data() : dataTypeID(UNKNOWN) {}
	Data(int newDataTypeID) : dataTypeID(newDataTypeID) {}
	// Setters
	void setDataType(int newDataTypeID) { dataTypeID = newDataTypeID; }
	// Getters
	int getDataType() const { return dataTypeID; }
	// Helpers
	friend inline ostream& operator<<(ostream& out, const Data &d) 
	{ 
		d.print(out); 
		return out;
	}
	virtual ostream& print(ostream& out) const
	{
		out << "Nothing here.";
		return out;
	}
private:
	int dataTypeID;
};

#endif