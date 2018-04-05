#pragma once
#ifndef ACCESSDATABASE_H
#define ACCESSDATABASE_H

#include "database.h"

class accessDatabase : database {
private:
	map <string, double> userDateTri;
	map <string, double> userDataGpaTri;
	map <string, vector<double>>tempGPA;
	map <string, string>tempID;
	map <string, string>tempName;

public:
	accessDatabase();
	void outputStudentInfoByTri(int);
	void storeStudentInfoByGPATri(double, int);
	void updateStudentInfo(string, int, double);
	void outputStudentInfoByGPATri(int, double);
};

#endif // !ACCESSDATABASE_H
