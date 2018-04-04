#include "stdafx.h"
#include "database.h"
#include <ctime>
#include <cstdlib>

database::database()
{
}

void database::createDatabase()
{
	string firstName, lastName, ID;
	int dSize, fSize, lSize;

	dSize = randomDataSize();
	for (int i = 0; i < dSize; i++) {
		fSize = randomNameSize();
		for (int j = 0; j < fSize; j++) {
			char fName = randomName();
			firstName = firstName + fName;
		}

		lSize = randomNameSize();
		for (int k = 0; k < lSize; k++) {
			char lName = randomName();
			lastName = lastName + lName;
		}

		name.insert(firstName, lastName);

		for (int l = 0; l < 9; l++) {
			char identification = randomID();
			ID = ID + identification;
		}
		this->ID.insert(firstName, ID);

		this->GPA[firstName];
		for (int m = 0; m < 9; m++) {
			double GPA = randomGPA();
			this->GPA[firstName].push_back(GPA);
		}

		firstName = "";
		lastName = "";
		ID = "";
	}
}

int database::randomDataSize()
{
	int dataSize;

	srand(time(NULL));
	dataSize = rand() + 10000;

	return dataSize;
}

int database::randomNameSize()
{
	int nameSize;

	srand(time(NULL));
	nameSize = rand() % 20 + 2;

	return nameSize;
}

char database::randomName()
{
	int ascii;
	char name;

	srand(time(NULL));
	ascii = rand() % 25;

	name = (ascii + 97);

	return name;
}

char database::randomID()
{
	int choice, size;
	char ID;

	srand(time(NULL));
	choice = rand() % 1;

	if (choice == 0) {
		size = rand() % 10;
		ID = (size + 48);
	}
	else {
		size = rand() % 25;
		ID = (size + 65);
	}

	return ID;
}

double database::randomGPA()
{
	double GPA;

	srand(time(NULL));
	GPA = rand() % 4;

	return GPA;
}
