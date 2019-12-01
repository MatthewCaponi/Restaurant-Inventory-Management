#ifndef COMMENT_H
#define COMMENT_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class Comment
{
public:
	// Constructors
	Comment() {}
	Comment(const string &newComment, const string &newName, const Date &newDate)
		: comment(newComment), name(newName), date(newDate) {}
	// Setters
	void setComment(const string &newComment) { comment = newComment; }
	void setName(const string &newName) { name = newName; }
	void setDate(const Date &newDate) { date = newDate; }
	// Getters
	string getComment() const { return comment; }
	string getName() const { return name; }
	Date getDate() const { return date; }
	// Helpers
	friend ostream& operator<<(ostream& out, const Comment &c)
	{
		out << " On " << c.date << ", " << c.name << " wrote: " << endl;
		out << " " << c.comment << endl;
		return out;
	}
	// Destructors
	~Comment() {}
private:
	string comment, name;
	Date date;
};


#endif