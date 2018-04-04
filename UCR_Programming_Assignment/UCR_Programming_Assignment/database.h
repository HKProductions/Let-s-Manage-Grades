#pragma once
#ifndef DATABASE_H
#define DATABASE_H

#include <map>
#include <vector>

using namespace std;

class database {
protected:
	map <string, string> name;
	map <string, string> ID;
	map <string, vector<double> > GPA;

public:
	database();
	void createDatabase();
	int randomDataSize();
	int randomNameSize();
	char randomName();
	char randomID();
	double randomGPA();
};

#endif 

