#ifndef EMPLOYEE_COMMENTS_IO_H
#define EMPLOYEE_COMMENTS_IO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include "Comment.h"
#include "Date.h"

using namespace std;

inline list<Comment> readComment()
{
	list<Comment> comments;
	ifstream in;
	in.open("EmployeeComments.txt");
	string line;
	getline(in, line);
	while (in.good() && !line.empty())
	{
		string comment, name, date;
		name = line;
		getline(in, comment);
		getline(in, date);
		comments.push_back(Comment(comment, name, Date(date)));
		getline(in, line);
	}

	in.close();
	return comments;
}

inline void writeComment(const Comment &c)
{
	ofstream out;
	out.open("EmployeeComments.txt", ofstream::app);
	out << c.getName() << endl;
	out << c.getComment() << endl;
	out << c.getDate().toFormat() << endl;

	out.close();
}

inline void deleteComments()
{
	ofstream out;
	out.open("EmployeeComments.txt", ofstream::trunc);

	out.close();

}



#endif
