#include "AlternativeManager.h"
#include <fstream>
#include <iostream>

using namespace std;

int AlternativeManager::currentID = 0;

AlternativeManager::AlternativeManager()
{
}

AlternativeManager::~AlternativeManager()
{
	for (int i = 0; i < size(); i++)
    {
    	delete mAlternatives[i];
    }
    mAlternatives.clear();
}

void AlternativeManager::addAlternative(Alternative *alter)
{
    alter->setID(currentID);
    currentID++;
	mAlternatives.push_back(alter);
}

Alternative* AlternativeManager::getAlternative(int index)
{
	return mAlternatives.at(index);
}

void AlternativeManager::loadAlternativeFromFile(string filePath)
{
    int n;
    string alternative;

    ifstream f(filePath.c_str());
    
    if (f == NULL)
        cout<<"File "<<filePath<<"Not found"<<endl;

    f >> n;
    f.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(f, alternative);
        Alternative *a = new Alternative(alternative);
        this->addAlternative(a);
    }

    f.close();
}

int AlternativeManager::size()
{
	return mAlternatives.size();
}

void AlternativeManager::display()
{
	for (int i = 0; i < size(); i++)
    {
    	mAlternatives[i]->display();
    }
}
