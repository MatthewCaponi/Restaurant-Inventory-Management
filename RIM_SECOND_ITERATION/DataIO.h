#ifndef DATA_IO_H
#define DATA_IO_H


#define INGREDIENT_BOW 0
#define INGREDIENT_EOW 1
#define INGREDIENT_WASTE 2
#define INGREDIENT_ORDER 3
#define MENU_ITEM_SALES 4
#define SHIPMENTS 5

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <queue>
#include "Data.h"
#include "Date.h"
#include "Ingredient.h"
#include "MenuItem.h"

using namespace std;

inline list<Ingredient> readIngredients()
{
	list<Ingredient> ingredients;

	ifstream infile;
	infile.open("Data.csv");

	if (!infile)
	{
		system("CLS");
		cerr << "Input file does not exist." << endl;
		system("Pause");
		exit(1);
	}

	string line;
	bool found = false;
	getline(infile, line);
	while (infile.good() && !found && !line.empty())
	{
		if (line[0] == '#' && line.substr(1) == "INGREDIENTS")
		{
			found = true;
		}
		else
			getline(infile, line);
	}

	if (found)
	{
		getline(infile, line);
		istringstream in_str;
		while (line[0] != '#' && !line.empty())
		{
			in_str.str(line);
			string name, baseCostPerUnitStr, baseExpirationStr;
			getline(in_str, name, ',');
			getline(in_str, baseCostPerUnitStr, ',');
			getline(in_str, baseExpirationStr, ',');

			ingredients.push_back(Ingredient(name, stod(baseCostPerUnitStr), stoi(baseExpirationStr)));
			
			getline(infile, line);
			in_str.clear();
		}
	}

	return ingredients;
}

inline list<MenuItem> readMenuItems()
{
	list<MenuItem> menu;

	ifstream infile;
	infile.open("Data.csv");

	if (!infile)
	{
		system("CLS");
		cerr << "Input file does not exist." << endl;
		system("Pause");
		exit(1);
	}

	string line, prevLine;
	bool found = false;
	getline(infile, line);
	while (infile.good() && !found && !line.empty())
	{
		if (line[0] == '#' && line.substr(1) == "MENU_ITEMS")
		{
			found = true;
		}
		else
			getline(infile, line);
	}

	if (found)
	{
		getline(infile, line);
		istringstream in_str;
		while (line[0] != '#' && !line.empty() && prevLine != line)
		{
			in_str.str(line);

			string name, priceStr, piece;
			list<Ingredient> ingredients;
			queue<string> ingredientPieces;

			getline(in_str, name, ',');
			getline(in_str, priceStr, ',');
			while (getline(in_str, piece, ','))
				ingredientPieces.push(piece);

			while (!ingredientPieces.empty())
			{
				string ingredientName = ingredientPieces.front();
				ingredientPieces.pop();

				int ingredientAmount = stoi(ingredientPieces.front());
				ingredientPieces.pop();

				ingredients.push_back(Ingredient(ingredientName, ingredientAmount));
			}

			double price = stod(priceStr);

			menu.push_back(MenuItem(name, price, ingredients));
			prevLine = line;
			getline(infile, line);
			in_str.clear();
		}
	}

	return menu;
}

inline list<Ingredient> readIngredientType(const string &id)
{
	list<Ingredient> result;
	int id_DataType = int(id[2] - 48);
	if (id_DataType == INGREDIENT_BOW || id_DataType == INGREDIENT_EOW || id_DataType == INGREDIENT_WASTE || id_DataType == INGREDIENT_ORDER)
	{
		ifstream infile;
		infile.open("Data.csv");

		string line, prevLine;
		bool found = false;

		getline(infile, line);
		while (infile.good() && !found)
		{
			if (line == id)
				found = true;
			else
				getline(infile, line);
		}

		if (found)
		{
			getline(infile, line);
			istringstream in_str;
			while (line[0] != '#' && !line.empty() && prevLine != line)
			{
				in_str.str(line);
				string name, amountStr;
				getline(in_str, name, ',');
				getline(in_str, amountStr, ',');

				result.push_back(Ingredient(name, stoi(amountStr)));

				list<Ingredient> ingredients = readIngredients();
				for (Ingredient &i : ingredients)
					if (result.rbegin()->getName() == i.getName())
					{
						result.rbegin()->setBaseCostPerUnit(i.getBaseCostPerUnit());
						result.rbegin()->setBaseExpiration(i.getBaseExpiration());
					}

				prevLine = line;
				getline(infile, line);
				in_str.clear();
			}
		}
	}
	return result;
}

inline void writeIngredientType(const list<Ingredient> &ingredientList, const Date &d, int id_DataType)
{
	if (id_DataType == INGREDIENT_BOW || id_DataType == INGREDIENT_EOW || id_DataType == INGREDIENT_WASTE || id_DataType == INGREDIENT_ORDER)
	{
		ifstream infile;
		infile.open("Data.csv");

		ostringstream id_oss;
		id_oss << "#" << id_DataType;
		id_oss << setfill('0') << setw(2) << d.getMonth();
		id_oss << setfill('0') << setw(2) << d.getDay();
		id_oss << setfill('0') << setw(4) << d.getYear();

		string id = id_oss.str();

		bool found = false;
		string line;
		getline(infile, line);
		while (infile.good() && !line.empty() && !found)
		{
			if (line.find(id) != string::npos)
				found = true;
			else
				getline(infile, line);
		}
		infile.close();

		if (found)
		{
			infile.open("Data.csv");
			ofstream outfile_copy;
			outfile_copy.open("Data_copy.csv", ofstream::trunc);

			getline(infile, line);
			while (infile.good() && !line.empty() && line.find(id) == string::npos)
			{
				outfile_copy << line + "\n";
				getline(infile, line);
			}

			// print text header
			outfile_copy << line + "\n";
			getline(infile, line);

			// print new content
			list<Ingredient>::const_iterator iter = ingredientList.begin();
			list<Ingredient>::const_reverse_iterator revIter = ingredientList.rbegin();

			while (iter != ingredientList.end())
			{
				outfile_copy << iter->getName() << "," << iter->getAmount() << "\n";
				++iter;
			}

			while (infile.good() && !line.empty() && line.find('#') == string::npos)
				getline(infile, line);

			while (infile.good() && !line.empty())
			{
				outfile_copy << line + "\n";
				getline(infile, line);
			}
			infile.close();
			outfile_copy.close();

			ifstream infile_copy;
			infile_copy.open("Data_copy.csv");
			ofstream outfile;
			outfile.open("Data.csv", ofstream::trunc);

			getline(infile_copy, line);
			while (infile_copy.good() && !line.empty())
			{
				outfile << line + "\n";
				getline(infile_copy, line);
			}

			infile_copy.close();
			outfile.close();
			if (remove("Data_copy.csv") != 0)
			{
				system("CLS");
				cerr << "Failed to delete copy." << endl;
				system("Pause");
				exit(1);
			}
		}
		else
		{
			ofstream outfile;
			outfile.open("Data.csv", ofstream::app);

			list<Ingredient>::const_iterator iter = ingredientList.begin();
			list<Ingredient>::const_reverse_iterator revIter = ingredientList.rbegin();
			bool isFinal = false;

			outfile << "\n";
			outfile << id;
			outfile << "\n";

			while (iter != ingredientList.end())
			{
				isFinal = iter->getName() == revIter->getName();
				outfile << iter->getName() << "," << iter->getAmount() << ((!isFinal) ? "\n" : "");
				++iter;
			}
			outfile.close();
		}


	}
	else
	{
		system("CLS");
		cerr << "Writing error has occurred!" << endl;
		system("Pause");
		exit(1);
	}
}

inline list<MenuItem> readMenuItemType(const string &id)
{
	list<MenuItem> result;

	ifstream infile;
	infile.open("Data.csv");

	string line, prevLine;
	bool found = false;

	getline(infile, line);
	while (infile.good() && !found)
	{
		if (line == id)
			found = true;
		else
			getline(infile, line);
	}

	if (found)
	{
		getline(infile, line);
		istringstream in_str;
		while (line[0] != '#' && !line.empty() && prevLine != line)
		{
			in_str.str(line);
			string name, amountStr;
			getline(in_str, name, ',');
			getline(in_str, amountStr, ',');

			result.push_back(MenuItem(name, stoi(amountStr)));

			prevLine = line;
			getline(infile, line);
			in_str.clear();
		}
	}

	for (MenuItem &m : readMenuItems())
	{
		for (MenuItem &mSales : result)
		{
			if (m.getName() == mSales.getName())
			{
				mSales.setIngredients(m.getIngredients());
				mSales.setPrice(m.getPrice());
			}

		}
	}
	return result;
}

inline void writeMenuItemType(const list<MenuItem> &menuList, const Date &d, int id_DataType)
{
	if (id_DataType == MENU_ITEM_SALES)
	{
		ifstream infile;
		infile.open("Data.csv");

		ostringstream id_oss;
		id_oss << "#" << id_DataType;
		id_oss << setfill('0') << setw(2) << d.getMonth();
		id_oss << setfill('0') << setw(2) << d.getDay();
		id_oss << setfill('0') << setw(4) << d.getYear();

		string id = id_oss.str();

		bool found = false;
		string line;
		getline(infile, line);
		while (infile.good() && !line.empty() && !found)
		{
			if (line.find(id) != string::npos)
				found = true;
			else
				getline(infile, line);
		}
		infile.close();

		if (found)
		{
			infile.open("Data.csv");
			ofstream outfile_copy;
			outfile_copy.open("Data_copy.csv", ofstream::trunc);

			getline(infile, line);
			while (infile.good() && !line.empty() && line.find(id) == string::npos)
			{
				outfile_copy << line + "\n";
				getline(infile, line);
			}

			// print text header
			outfile_copy << line + "\n";
			getline(infile, line);

			// print content
			list<MenuItem>::const_iterator iter = menuList.begin();
			list<MenuItem>::const_reverse_iterator revIter = menuList.rbegin();

			while (iter != menuList.end())
			{
				outfile_copy << iter->getName() << "," << iter->getAmountSold() << "\n";
				++iter;
			}
			while (infile.good() && !line.empty() && line.find('#') == string::npos)
				getline(infile, line);

			while (infile.good() && !line.empty())
			{
				outfile_copy << line + "\n";
				getline(infile, line);
			}
			infile.close();
			outfile_copy.close();

			ifstream infile_copy;
			infile_copy.open("Data_copy.csv");
			ofstream outfile;
			outfile.open("Data.csv", ofstream::trunc);

			getline(infile_copy, line);
			while (infile_copy.good() && !line.empty())
			{
				outfile << line + "\n";
				getline(infile_copy, line);
			}

			infile_copy.close();
			outfile.close();
			if (remove("Data_copy.csv") != 0)
			{
				system("CLS");
				cerr << "Failed to delete copy." << endl;
				system("Pause");
				exit(1);
			}
		}
		else
		{
			ofstream outfile;
			outfile.open("Data.csv", ofstream::app);

			list<MenuItem>::const_iterator iter = menuList.begin();
			list<MenuItem>::const_reverse_iterator revIter = menuList.rbegin();
			bool isFinal = false;

			outfile << "\n";
			outfile << id;
			outfile << "\n";
			while (iter != menuList.end())
			{
				isFinal = iter->getName() == revIter->getName();
				outfile << iter->getName() << "," << iter->getAmountSold() << ((!isFinal) ? "\n" : "");
				++iter;
			}

			outfile.close();
		}
	}
	else
	{
		system("CLS");
		cerr << "Writing error has occurred." << endl;
		system("Pause");
		exit(1);
	}

}


#endif