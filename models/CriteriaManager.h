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
	void loadCriteriaFromFile(string filePath);
	void loadPQWFromFile(string filePath);

	int size();
	void display();
	
	float *P;
	float *Q;
	float *W;
	int pqwSize;
	
private:
	std::vector<Criteria*> mCriterias;
	static int currentID;
};
