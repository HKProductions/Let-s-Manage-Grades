// UCR_Programming_Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "database.h"
#include "accessDatabase.h"


int main()
{

	database db;
	db.createDatabase();

	cout << "Database Created \n";

	accessDatabase aDB;
	aDB.outputStudentInfoByTri(3);

    return 0;
}

