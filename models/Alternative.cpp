#include "Alternative.h"
#include <iostream>

Alternative::Alternative()
{
	setName("N/A");
}

Alternative::Alternative(string name)
{
	setName(name);
}

Alternative::~Alternative()
{
}

void Alternative::setName(string name)
{
	mName = name;
}

string Alternative::getName()
{
	return mName;
}

void Alternative::setID(int id)
{
	mID = id;
}

int Alternative::getID()
{
	return mID;
}

void Alternative::display()
{
	cout<<"Name: "<<getName()<<", ID: "<<mID<<endl;
}

void Alternative::input()
{
	cout<<endl<<"+================================+"<<endl;
	cout<<"====Input Alternative name: ";
	string tempName;
	cin.ignore();
	getline(cin, tempName);
	setName(tempName);
	cout<<endl;
}
