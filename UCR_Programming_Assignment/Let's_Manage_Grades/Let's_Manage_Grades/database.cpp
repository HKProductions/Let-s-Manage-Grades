#include "database.h"
#include <ctime>
#include <cstdlib>
#include <iomanip>

void database::createDatabase()
{
	string firstName, ID;
	int dSize;

	srand(time(0));

	dSize = rand() % 30000 + 10000;
	for (int i = 0; i < 10000; i++) {
		firstName = randomName();

		ID = randomID();

		this->ID[ID] = firstName;
		findID[firstName] = ID;
		
		randomGPA(ID);

		firstName = "";
		ID = "";
	}
}

string database::randomName()
{
	int ascii, fSize, lSize;
	char character;
	string firstName = "",
		lastName = "";
	map <string, string>::iterator iter;

	srand(time(0));

	do {
		firstName = "";
		fSize = rand() % 20 + 2;
		for (int i = 0; i < fSize; i++) {
			ascii = rand() % 25;
			character = (ascii + 97);
			firstName = firstName + character;
		}
		iter = name.find(firstName);
	} while (iter != name.end());

	lSize = rand() % 19 + 2;
	for (int i = 0; i < lSize; i++) {
		ascii = rand() % 25;
		character = (ascii + 97);
		lastName = lastName + character;
	}

	name[firstName] = lastName;

	return firstName;
}

string database::randomID()
{
	int choice, size;
	char number;
	string ID;
	map <string, string>::iterator iter;

	srand(time(0));

	do {
		ID = "";
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
		iter = this->ID.find(ID);
	} while (iter != this->ID.end());

	return ID;
}

void database::randomGPA (string id)
{
	double GPA;

	srand(time(0)); 
	for (int i = 0; i < 9; i++){
		GPA = rand() % (40 - 0) / 10.0;
		this->GPA[id].push_back(GPA);
	}
}

void database::outputStudentInfo()
{
	string firstName;
	string lastName;
	string id;
	vector<double>gpa;

	for (const auto &i : GPA) {
		gpa.clear();

		for (double v : i.second) {
			gpa.push_back(v);
		}

		firstName = ID[i.first];
		lastName = name[firstName];
		id = i.first;

		cout << id << " " << firstName << " " << lastName << gpa[0] << " " << gpa[1] << " ";
		cout << gpa[2] << " " << gpa[3] << " " << gpa[4] << " " << gpa[5] << " " << gpa[6];
		cout << " " << gpa[7] << " " << gpa[8];
	}
}

void database::outputStudentInfoByTri(int trimester)
{
	for (const auto &i : this->GPA) {
		double GPA;

		string firstName = ID[i.first];
		string lastName = name[firstName];
		string name = firstName + " " + lastName;

		int iter = 0;
		for (double v : i.second) {
			if (iter >= trimester)
				break;

			else if (iter == trimester - 1) {
				GPA = v;
				break;
			}

			iter++;
		}

		userDateTri[name] = GPA;
	}

	for (const auto &j : userDateTri) {
		string name = j.first;
		double GPA = j.second;

		cout << name << " " << GPA << endl;
	}
}

void database::storeStudentInfoByGPATri(int I, double gpa)
{
	for (const auto &i : this->GPA) {
		int iter = 0;
		for (double v : i.second) {
			if (iter >= I)
				break;

			else if (iter == I - 1) {
				if (v == gpa) {
					userDataGpaTri[i.first] = v;
					break;
				}
			}
			iter++;
		}
	}
}

void database::updateStudentInfo(string fName, int tri, double gpa)
{
	string getID = findID[fName];

	for (auto &i : GPA) {
		if (i.first == getID) {
			i.second.at(tri-1) = gpa;
			break;
		}
	}
}

void database::outputStudentInfoByGPATri(int g, double t)
{
	userDataGpaTri.clear();
	storeStudentInfoByGPATri(g, t);

	for (const auto &i : userDataGpaTri) {
		string firstName = ID[i.first];
		string lastName = name[firstName];
		double GPA = i.second;

		cout << firstName << " " << lastName << " " << GPA << endl;
	}
}
