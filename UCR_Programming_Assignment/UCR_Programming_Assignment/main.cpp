// UCR_Programming_Assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "database.h"
#include "accessDatabase.h"


int main()
{

	database db;
	db.createDatabase();

	accessDatabase  aDB;
    return 0;
}

