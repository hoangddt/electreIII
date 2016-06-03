#pragma once
#include "../models/AlternativeManager.h"
#include "../models/CriteriaManager.h"

class Compute
{
public:
	Compute();
	~Compute();
	
	void loadPerformanceMatrixFromFile(string filePath);
	void displayMatrix();
	void calculateCMatrix(CriteriaManager *cm);
	void calculateDMatrix(CriteriaManager *cm);
	void calculateSMatrix();
	int outputResult(AlternativeManager *am);

	float** mMatrix;
	float** mCMatrix;
	float** mDMatrix;
	float** mSMatrix;
	int mC;
	int m, n;
};
