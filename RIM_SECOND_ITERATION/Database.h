#ifndef DATABASE_H
#define DATABASE_H

#include "Data.h"
#include <list>
#include <vector>
#include <string>
using namespace std;

class Database
{
public:
	// Constructors
	Database();
	Database(const string &newDatabaseID);
	// Setters
	void setDatabaseID(const string &newDatabaseID);
	void setData(const list<Data*> &newData);
	// Getters
	string getDatabaseID() const;
	list<Data*> getData() const;
	// Helpers
	friend ostream& operator<<(ostream& out, const Database &d);
	// Deconstructors 
	~Database();
private:
	/*
	Database ID: 
		1 - Datatype
		2 - 9 Date of beginning of week
		10* - Week
	*/
	string databaseID;
	list<Data*> data;
};

#endif