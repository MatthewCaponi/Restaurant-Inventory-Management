#include "CommentsSubmission.h"
#include "CommentsBoardMenu.h"
#include "Comment.h"
#include "EmployeeCommentsIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
CommentsSubmission::CommentsSubmission()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void CommentsSubmission::setup()
{

}

void CommentsSubmission::run()
{
	if (isEmployee)
	{
		string name, message;
		cout << " Name: ";
		cout << " ";
		getline(cin, name);
		cout << " Message: " << endl;
		cout << " ";
		getline(cin, message);
		cout << endl;

		string input;
		cout << " Submit? (Y/N): ";
		bool answered = false, submit = false;
		while (!answered)
		{
			cout << " ";
			getline(cin, input);
			for (char &c : input)
				c = toupper(c);
			if (input == "Y")
			{
				submit = true;
				answered = true;
			}
			else if (input == "N")
			{
				submit = false;
				answered = true;
			}
			else
			{
				system("CLS");
				cout << " Name: " + name << endl;
				cout << " Message: " << endl << message << endl;
				cout << " Invalid entry. Try again." << endl;
				cout << " Submit? (Y/N): ";
			}
		}
		if (submit)
		{
			cout << " Suggestion / message submitted!" << endl;
			Comment c(message, name, Date());
			writeComment(c);
		}
		else
			cout << " Message discarded!" << endl;
	}
	cout << endl;
	system("Pause");
}

void CommentsSubmission::menu()
{
	nextDisplay = new CommentsBoardMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
CommentsSubmission::~CommentsSubmission() {}