#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <vector>

using namespace std;

class database {
private:
	map <string, string> name;
	map <string, string> ID;
	map <string, vector<double> > GPA;

public:
	void createDatabase();
	string randomName(int);
	string randomID();
	double randomGPA();
	map <string, string> getName();
	map <string, string> getID();
	map <string, vector<double>> getGPA();
};

#endif 

