#include "Shipment.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
Shipment::Shipment() : Data(SHIPMENT)
{

}

Shipment::Shipment(const string &newShipmentID, const Date &newShipmentDate) : Data(SHIPMENT)
{
	shipmentID = newShipmentID;
	shipmentDate = newShipmentDate;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setters
void Shipment::setShipmentID(const string &newShipmentID)
{
	shipmentID = newShipmentID;
}

void Shipment::setShipmentDate(const Date& newShipmentDate)
{
	shipmentDate = newShipmentDate;
}

void Shipment::setShipmentGroups(const list<ShipmentGroup> &newShipmentGroups)
{
	shipmentGroups = newShipmentGroups;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Getters
string Shipment::getShipmentID() const
{
	return shipmentID;
}

Date Shipment::getShipmentDate() const
{
	return shipmentDate;
}

list<ShipmentGroup> Shipment::getShipmentGroups() const
{
	return shipmentGroups;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
ostream& Shipment::print(ostream &out) const
{
	out << "ID: " << shipmentID << " | date of shipment: " << shipmentDate << endl;
	out << "Shipment Groups: " << endl;
	int count = 1;
	for (auto &shipmentGroup : shipmentGroups)
	{
		out << "  " << count << ": " << shipmentGroup << endl;
		++count;
	}

	return out;
}

ostream& operator<<(ostream& out, const Shipment &s)
{
	s.print(out);
	return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
Shipment::~Shipment() {}