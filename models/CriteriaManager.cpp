#include "CriteriaManager.h"


CriteriaManager::CriteriaManager()
{
}

CriteriaManager::~CriteriaManager()
{
	for (int i = 0; i < size(); i++)
    {
    	delete mCriterias[i];
    }
    mCriterias.clear();
}

void CriteriaManager::addCriteria(Criteria *cri)
{
	mCriterias.push_back(cri);
}

Criteria* CriteriaManager::getCriteria(int index)
{
	return mCriterias.at(index);
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
