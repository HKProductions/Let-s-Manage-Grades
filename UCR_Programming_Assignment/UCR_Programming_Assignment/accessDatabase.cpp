#include "stdafx.h"
#include "accessDatabase.h"
#include <iostream>
#include <string>

accessDatabase::accessDatabase()
{
	tempGPA.swap(getGPA());
	tempID.swap(getID());
	tempName.swap(getName());
}

void accessDatabase::outputStudentInfoByTri(int trimester)
{
	for (const auto &i : tempGPA) {
		double GPA;

		string firstName = tempID[i.first];
		string lastName = tempName[firstName];
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

void accessDatabase::storeStudentInfoByGPATri(double gpa, int I)
{
	for (const auto &i : tempGPA) {
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

void accessDatabase::updateStudentInfo(string, int, double)
{

}

void accessDatabase::outputStudentInfoByGPATri(int g, double t)
{
	userDataGpaTri.clear();
	storeStudentInfoByGPATri(g, t);

	for (const auto &i : userDataGpaTri) {
		string firstName = i.first;
		string lastName = tempName[firstName];
		double GPA = i.second;

		cout << firstName << " " << lastName << " " << GPA << endl;
	}
}
