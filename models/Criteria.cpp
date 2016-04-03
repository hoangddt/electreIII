#include "Criteria.h"
#include <iostream>

Criteria::Criteria()
{
}

Criteria::Criteria(string name)
{
	setName(name);
	Weight = Vecto = P = Q = 0;
}

Criteria::~Criteria()
{
	Weight = Vecto = P = Q = 0;
}

void Criteria::setName(string name)
{
	mName = name;
}

string Criteria::getName()
{
	return mName;
}

void Criteria::setID(string id)
{
	mID = id;
}

string Criteria::getID()
{
	return mID;
}

void Criteria::display()
{
	cout<<"This is Criteria: "<<getName()<<endl;
	cout<<"p, q, w , v, id: "<<   P
						<<", "<<Q
						<<", "<<Weight
						<<", "<<Vecto
						<<", "<<mID
						<<endl;
}

void Criteria::input()
{
	cout<<"Input Criteria Name: ";
	string tempName;
	getline(cin, tempName);
	setName(tempName);
}