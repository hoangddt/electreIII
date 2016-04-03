#pragma once
#include <vector>
#include "Criteria.h"

using namespace std;


class CriteriaManager
{
public:
	CriteriaManager();
	~CriteriaManager();
	
	void addCriteria(Criteria *cri);
	Criteria* getCriteria(int index);
	int size();
	void display();
	
private:
	std::vector<Criteria*> mCriterias;
};
