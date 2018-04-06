#include "database.h"
#include <stdlib.h>

void menu();
void printStudentsBasedOnTri();
void updateStudentGPAByTri();
void printStudentsBasedOnGPATri();

int main()
{
	system("CLS");
	cout << "Creating Database...\n" << flush;

	database db;
	db.createDatabase();

	system("CLS");
	cout << "Database Created \n" << flush;

	menu();

	return 0;
}

void menu() {
	int input;

	do {
		system("CLS");
		cout << "Welcome to St. Arrrrghhh's High School Database \n" << flush;
		cout << "1. Print out all students's names and GPA for a specific trimester \n" << flush;
		cout << "2. Update a student's GPA for a specific trimester \n" << flush;
		cout << "3. Print out all student's names and GPA based on a specific GPA and trimester \n" << flush;
		cout << "4. Quit Database \n\n" << flush;
		cout << "Please enter in your choice: ";
		cin >> input;

		if (input == 1) {
			printStudentsBasedOnTri();
		}
		else if (input == 2) {
			updateStudentGPAByTri();
		}
		else if (input == 3) {
			printStudentsBasedOnGPATri();
		}
	} while (input != 4);
}

void printStudentsBasedOnTri() {
	int trimester;
	char repeat;
	database db;

	do {
		system("CLS");
		cout << "So which trimester are you trying to get all the student names and GPA for (1-9): ";
		cin >> trimester;

		db.outputStudentInfoByTri(trimester);

		cout << "\n\nDo you want to run this program again or go back to the main menu: ";
		cin >> repeat;

		repeat = tolower(repeat);
	} while (repeat == 'y');
}

void updateStudentGPAByTri() {
	string fName;
	double gpa;
	int trimester;
	char repeat;
	database db;

	do {
		system("CLS");
		db.outputStudentInfo();

		cout << endl << endl;
		cout << "What student do you want to change the GPA for (Just type in the first name): ";
		cin >> fName;

		cout << "What trimester do you want to change the student's GPA for (1-9): ";
		cin >> trimester;

		cout << "What GPA do you want to change the student's GPA to (0.0 - 4.0): ";
		cin >> gpa;

		db.updateStudentInfo(fName, trimester, gpa);

		db.outputStudentInfo();

		cout << "Do you want to run this program again: ";
		cin >> repeat;
		repeat = tolower(repeat);
	} while (repeat == 'y');
}

void printStudentsBasedOnGPATri() {
	int trimester;
	double gpa;
	char repeat;
	database db;

	do {
		system("CLS");
		cout << "What trimester are you trying to gain access to: ";
		cin >> trimester;

		cout << "What GPA do you want the students to have: ";
		cin >> gpa;

		db.outputStudentInfoByGPATri(trimester, gpa);

		cout << "\n\nDo you want to run this program again or go back to the main menu: ";
		cin >> repeat;

		repeat = tolower(repeat);
	} while (repeat == 'y');
}