#ifndef DISPLAY_H
#define DISPLAY_H
#include "Database.h"
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Display
{
public:
	// Constructors
	Display() : isEmployee(false), nextDisplay(nullptr) {}
	// Setters
	void setNextDisplay(Display *newNextDisplay) { nextDisplay = newNextDisplay; }
	void setIsEmployee(bool newIsEmployee) { isEmployee = newIsEmployee; }
	void setContent(const string &newContent) { content = newContent; }
	// Getters
	Display* getNextDisplay() const { return nextDisplay; }
	bool getIsEmployee() const { return isEmployee; }
	string getContent() const { return content; }
	// Helpers
	virtual void setup() = 0;
	virtual void run() = 0;
	virtual void menu() = 0;
	inline bool isValidResponse(string response, int &inputNum, int min, int max)
	{
		for (char &c : response)
		{
			if (!isdigit(c))
				return false;
		}
		stringstream inputStream(response);
		inputStream >> inputNum;
		return (inputNum <= max && inputNum >= min);
	}
	// Destructors
	~Display() { nextDisplay = nullptr; }
protected:
	Display* nextDisplay;
	string content; // not necessarily used
	bool isEmployee;
};


#endif