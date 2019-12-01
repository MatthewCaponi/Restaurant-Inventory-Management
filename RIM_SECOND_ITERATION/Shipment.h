#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
#include <list>
#include <iostream>
#include <ctime>
#include "ShipmentGroup.h"
#include "Date.h"

using namespace std;

class Shipment : public Data
{
public:
	// Constructors
	Shipment();
	Shipment(const string &newShipmentID, const Date &newShipmentDate);
	// Setters
	void setShipmentID(const string &newShipmentID);
	void setShipmentDate(const Date &newShipmentDate);
	void setShipmentGroups(const list<ShipmentGroup> &newShipmentGroups);
	// Getters
	string getShipmentID() const;
	Date getShipmentDate() const;
	list<ShipmentGroup> getShipmentGroups() const;
	// Helpers 
	ostream& print(ostream &out) const;
	friend ostream& operator<<(ostream& out, const Shipment &s);
	// Destructors
	~Shipment();
private:
	string shipmentID;
	Date shipmentDate;
	list<ShipmentGroup> shipmentGroups;
};


#endif

