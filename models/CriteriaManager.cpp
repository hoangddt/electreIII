#include "CriteriaManager.h"
#include <fstream>
#include <iostream>

using namespace std;

int CriteriaManager::currentID = 0;

CriteriaManager::CriteriaManager()
{
    P = NULL;
    Q = NULL;
    W = NULL;
    pqwSize;
}

CriteriaManager::~CriteriaManager()
{
	for (int i = 0; i < size(); i++)
    {
    	delete mCriterias[i];
    }
    mCriterias.clear();

    if (P != NULL)
        delete []P;
    if (Q != NULL)
        delete []P;
    if (W != NULL)
        delete []P;
}

void CriteriaManager::addCriteria(Criteria *cri)
{
    cri->setID(currentID);
    currentID++;
	mCriterias.push_back(cri);
}

Criteria* CriteriaManager::getCriteria(int index)
{
	return mCriterias.at(index);
}

void CriteriaManager::loadCriteriaFromFile(string filePath)
{
    int n;
    string criteria;

    ifstream f(filePath.c_str());

    if (f == NULL)
        cout<<"File "<<filePath<<"Not found"<<endl;
    
    f >> n;
    f.ignore();

    for (int i = 0; i < n; i++)
    {
        getline(f, criteria);
        Criteria *c = new Criteria(criteria);
        this->addCriteria(c);
    }

    f.close();
}

void CriteriaManager::loadPQWFromFile(string filePath)
{
    int n;

    ifstream f(filePath.c_str());
    if (f == NULL)
        cout<<"File "<<filePath<<"Not found"<<endl;
    
    f >> n;

    pqwSize = n;
    P = new float[n];
    Q = new float[n];
    W = new float[n];

    // read P
    for (int i = 0; i < n; i++)
    {
        f >> P[i];
    }

    // read Q
    for (int i = 0; i < n; i++)
    {
        f >> Q[i];
    }

    // read W
    for (int i = 0; i < n; i++)
    {
        f >> W[i];
    }

    f.close();
}

int CriteriaManager::size()
{
	return mCriterias.size();
}

void CriteriaManager::display()
{
	for (int i = 0; i < size(); i++)
    {
    	mCriterias[i]->display();
    }
}
