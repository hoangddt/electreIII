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

void Alternative::setID(string id)
{
	mID = id;
}

string Alternative::getID()
{
	return mID;
}

void Alternative::display()
{
	cout<<"This is Alternative: "<<getName()<<", ID: "<<mID<<endl;
}

void Alternative::input()
{
	cout<<"Input Alternative name: ";
	string tempName;
	getline(cin, tempName);
	setName(tempName);
}