#include "stdafx.h"
#include "database.h"
#include <ctime>
#include <cstdlib>

void database::createDatabase()
{
	string firstName, lastName, ID;
	int dSize, fSize, lSize;

	srand(time(0));

	for (int i = 0; i < 10000; i++) {
		fSize = rand() % 20 + 2;
		firstName = randomName(fSize);

		lSize = rand() % 19 + 2;
		lastName = randomName(lSize);

		name[firstName] = lastName;

		ID = randomID();

		this->ID[ID] = firstName;

		this->GPA[ID];
		for (int m = 0; m < 9; m++) {
			double GPA = randomGPA();
			this->GPA[ID].push_back(GPA);
		}

		firstName = "";
		lastName = "";
		ID = "";
	}
}

string database::randomName(int size)
{
	int ascii;
	char character;
	string name = "";

	srand(time(0));

	for (int i = 0; i < size; i++) {
		ascii = rand() % 25;
		character = (ascii + 97);
		name = name + character;
	}

	return name;
}

string database::randomID()
{
	int choice, size;
	char number;
	string ID;

	srand(time(0));

	for (int i = 0; i < 9; i++) {
		choice = rand() % 1;

		if (choice == 0) {
			size = rand() % 10;
			number = (size + 48);
		}
		else {
			size = rand() % 25;
			number = (size + 65);
		}

		ID = ID + number;
	}

	return ID;
}

double database::randomGPA()
{
	double GPA;

	srand(time(0));
	GPA = rand() % (40 - 0) /10.0 ;

	return GPA;
}

map<string, string> database::getName()
{
	return name;
}

map<string, string> database::getID()
{
	return ID;
}

map<string, vector<double>> database::getGPA()
{
	return GPA;
}
