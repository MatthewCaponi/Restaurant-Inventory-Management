#include "CommentsView.h"
#include "CommentsBoardMenu.h"
#include "Comment.h"
#include "EmployeeCommentsIO.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructors
CommentsView::CommentsView()
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
void CommentsView::setup()
{

}

void CommentsView::run()
{
	cout << "\n *** COMMENTS ***\n";
	list<Comment> comments = readComment();
	if (comments.empty())
		cout << " No comments / suggestions submtitted." << endl;
	else
	{
		for (Comment &c : comments)
			cout << c << endl;
	}
	
	cout << " ";
	system("Pause");
}

void CommentsView::menu()
{
	nextDisplay = new CommentsBoardMenu();
	nextDisplay->setIsEmployee(isEmployee);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Destructors
CommentsView::~CommentsView() {}