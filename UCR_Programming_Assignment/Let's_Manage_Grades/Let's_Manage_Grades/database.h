#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class database {
private:
	map <string, string> name;
	map <string, string> ID;
	map <string, string> findID;
	map <string, vector<double> > GPA;
	map <string, double> userDateTri;
	map <string, double> userDataGpaTri;

public:
	void createDatabase();
	string randomName();
	string randomID();
	void randomGPA(string);
	void outputStudentInfo();
	void outputStudentInfoByTri(int);
	void storeStudentInfoByGPATri(int, double);
	void updateStudentInfo(string, int, double);
	void outputStudentInfoByGPATri(int, double);
};

#endif 