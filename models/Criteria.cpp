#include "Criteria.h"
#include <iostream>

Criteria::Criteria()
{
}

Criteria::Criteria(string name)
{
	setName(name);
}

Criteria::~Criteria()
{
}

void Criteria::setName(string name)
{
	mName = name;
}

string Criteria::getName()
{
	return mName;
}

void Criteria::setID(int id)
{
	mID = id;
}

int Criteria::getID()
{
	return mID;
}

void Criteria::display()
{
	cout<<"Name: "<<getName()<<", ID: "<<mID<<endl;
}

