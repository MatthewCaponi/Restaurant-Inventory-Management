#include "CommentsBoardMenu.h"
#include "CommentsSubmission.h"
#include "CommentsView.h"
#include "CommentsDelete.h"
#include "MainMenu.h"
#include "Date.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
CommentsBoardMenu::CommentsBoardMenu() : Display () 
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void CommentsBoardMenu::setup()
{

}

void CommentsBoardMenu::run()
{
	
}

void CommentsBoardMenu::menu()
{
	bool answered = false;
	int choice;
	string response;
	showMenu();
	cout << endl;
	cout << " ";
	getline(cin, response);
	while (!answered)
	{
		if (isValidResponse(response, choice, 1, 3))
		{
			switch (choice)
			{
			case 1:
				if (isEmployee)
					nextDisplay = new CommentsSubmission();
				else
					nextDisplay = new CommentsView();
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 2:
				nextDisplay = new MainMenu();
				nextDisplay->setIsEmployee(isEmployee);
				answered = true;
				break;
			case 3:
				if (isEmployee)
				{
					system("CLS");
					showMenu();
					cout << " That's an invalid choice. Try again." << endl;
					cout << " ";
					getline(cin, response);
				}
				else
				{
					nextDisplay = new CommentsDelete();
					nextDisplay->setIsEmployee(isEmployee);
					answered = true;
				}
				break;
			}
			
		}
		else
		{
			system("CLS");
			showMenu();
			cout << " That's an invalid choice. Try again." << endl;
			cout << " "; 
			getline(cin, response);
		}
	}
}

void CommentsBoardMenu::showMenu()
{
	if (isEmployee)
	{
		cout << "\n *** COMMENTS BOARD MENU ***\n";
		cout << "\n Select one of the following:\n\n";
		cout << "    1: Submit a comment" << endl;
		cout << "    2: Back to main menu" << endl;
	} 
	else
	{
		cout << "\n *** COMMENTS BOARD MENU ***\n";
		cout << "\n Select one of the following:\n\n";
		cout << "    1: View comments" << endl;
		cout << "    2: Back to main menu" << endl;
		cout << "    3: Delete comments" << endl;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
CommentsBoardMenu::~CommentsBoardMenu() {}