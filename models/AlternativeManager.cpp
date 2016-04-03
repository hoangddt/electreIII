#include "AlternativeManager.h"


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
	mAlternatives.push_back(alter);
}

Alternative* AlternativeManager::getAlternative(int index)
{
	return mAlternatives.at(index);
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
