#include "Database.h"
#include "Comment.h"
#include "Ingredient.h"
#include "MenuItem.h"
#include "Shipment.h"
#include "ShipmentGroup.h"
#include "Display.h"
#include "MainMenu.h"
#include "DataIO.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

	Display *curr = new MainMenu(), *deleting = nullptr;
	cout << "\n *** WELCOME TO THE WILDCAT RIM! ***\n\n";
	cout << " Are you an employee, manager, or neither? (Type in correctly what you are): " << endl;
	string input;
	bool answered = false, isValidUser = false;
	while (!answered)
	{
		cout << " ";
		getline(cin, input);
		for (char &c : input)
			c = toupper(c);
		if (input == "EMPLOYEE")
		{
			curr->setIsEmployee(true);
			isValidUser = true;
			answered = true;
		}
		else if (input == "MANAGER")
		{
			curr->setIsEmployee(false);
			isValidUser = true;
			answered = true;
		}
		else if (input == "NEITHER")
		{
			isValidUser = false;
			answered = true;
		}
		else
		{
			system("CLS");
			cout << "\n *** WELCOME TO THE WILDCAT RIM! ***\n";
			cout << " That's an invalid response\n Are you an employee, manager, or neither? (Type in correctly what you are): " << endl;
		}
	}
	system("CLS");

	if (isValidUser)
	{
		while (curr != nullptr)
		{
			curr->setup();
			curr->run();
			curr->menu();
			system("CLS");
			deleting = curr;
			if (curr->getNextDisplay() != nullptr)
				curr->getNextDisplay()->setIsEmployee(curr->getIsEmployee());
			curr = curr->getNextDisplay();
			delete deleting;
		}

		cout << "\n *** THANKS FOR USING THE WILDCAT RIM! GOOD-BYE! ***\n";
		clock_t endwait;
		endwait = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < endwait) {}
	}
	else
	{
		cout << "\n *** YOU ARE NOT PERMITTED TO USE THIS PROGRAM. GOOD-BYE! ***\n";
		clock_t endwait;
		endwait = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < endwait) {}
	}
	
	/*Ingredient *i1 = new Ingredient, *i2 = new Ingredient, *i3 = new Ingredient, *i4 = new Ingredient, *i5 = new Ingredient;
	MenuItem *mi1 = new MenuItem, *mi2 = new MenuItem, *mi3 = new MenuItem;
	ShipmentGroup *sg1 = new ShipmentGroup, *sg2 = new ShipmentGroup, *sg3 = new ShipmentGroup, *sg4 = new ShipmentGroup, *sg5 = new ShipmentGroup;
	Shipment *s1 = new Shipment, *s2 = new Shipment, *s3 = new Shipment;

	i1->setName("First Ingredient");
	i2->setName("Second Ingredient");
	i3->setName("Third Ingredient");
	i4->setName("Fourth Ingredient");
	i5->setName("Fifth Ingredient");

	mi1->setName("First Menu Item");
	list<Ingredient> li1 = { *i1, *i2, *i3, *i4, *i5 };
	mi1->setIngredients(li1);
	mi2->setName("Second Menu Item");
	list<Ingredient> li2 = { *i3, *i4 };
	mi2->setIngredients(li2);
	mi3->setName("Third Menu Item");
	list<Ingredient> li3 = { *i1, *i2, *i5 };
	mi3->setIngredients(li3);

	sg1->setIngredient(*i1);
	sg2->setIngredient(*i2);
	sg3->setIngredient(*i3);
	sg4->setIngredient(*i4);
	sg5->setIngredient(*i5);
	Date d1;
	Date d2 = d1 - 20;
	Date d3 = d1 + 10;
	list<ShipmentGroup> lsg1 = { *sg1, *sg2, *sg3, *sg4, *sg5 };
	s1->setShipmentGroups(lsg1);
	s1->setShipmentDate(d1);
	s1->setShipmentID("ID1001040");
	list<ShipmentGroup> lsg2 = { *sg3, *sg4 };
	s2->setShipmentGroups(lsg2);
	s2->setShipmentDate(d2);
	s2->setShipmentID("ID2002195");
	list<ShipmentGroup> lsg3 = { *sg1, *sg2, *sg5 };
	s3->setShipmentGroups(lsg3);
	s3->setShipmentDate(d3);
	s3->setShipmentID("ID220105810");

	Database db1, db2, db3;
	list<Data*> dl1 = { i1, i2, i3, i4, i5 };
	db1.setData(dl1);
	list<Data*> dl2 = { mi1, mi2, mi3 };
	db2.setData(dl2);
	list<Data*> dl3 = { s1, s2, s3 };
	db3.setData(dl3);
	cout << db1 << endl;
	cout << db2 << endl;
	cout << db3 << endl;*/

	return 0;
}