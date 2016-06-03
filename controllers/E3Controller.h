#pragma once
#include "../models/AlternativeManager.h"
#include "../models/CriteriaManager.h"
#include "../views/Views.h"
#include "../views/Option.h"
#include "Compute.h"

class E3Controller
{
public:
	E3Controller();
	~E3Controller();

	void mainLoop();

	void alternativeProcessing();
	void addAlternative();
	void editAlternative();
	void deleteAlternative();

	void criteriaProcessing();
	void addCriteria();
	void loadPQW();
	void deleteCriteria();

	void computeProcessing();
	
private:
	AlternativeManager* mAM;
	CriteriaManager* mCM;
	View* mView;
	Compute* mCompute;
};
