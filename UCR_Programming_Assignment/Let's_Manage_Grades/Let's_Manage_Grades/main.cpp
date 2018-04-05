#include "database.h"

int main()
{

	database db;
	db.createDatabase();

	cout << "Database Created \n\n";

	cout << "Output all student names and GPA by trimester: ";
	db.outputStudentInfoByTri(3);
	cout << endl << endl;


	cout << "Output all student names and GPA by trimester and GPA: ";
	db.outputStudentInfoByGPATri(3, 3.5);
	cout << endl << endl;

	return 0;
}