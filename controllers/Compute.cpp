#include "compute.h"
#include <iostream>
#include <fstream>

using namespace std;

void alloc2DArray(int** &arr, int w, int h)
{
	arr = new int*[w];

	for (int i = 0; i < w; ++i)
	{
		arr[i] = new int[h];
	}
}

Compute::Compute()
{
	/*
	alloc2DArray(mMatrix, w, h);
	alloc2DArray(mCMatrix, w, w);
	alloc2DArray(mDMatrix, w, w);
	alloc2DArray(mSMatrix, w, w);
	*/
}

Compute::~Compute()
{
	for (int i = 0; i < m; ++i)
	{
		delete []mMatrix[i];
	}

	delete[] mMatrix;
}


void Compute::loadPerformanceMatrixFromFile(string filePath)
{    

    ifstream f(filePath.c_str());

    if (f == NULL)
        cout<<"File "<<filePath<<"Not found"<<endl;

    f >> m >> n;

    // m numbers of alternative
    // n numbers of criteria

    // performance matrix
    alloc2DArray(mMatrix, m, n);

    for (int i = 0; i < m; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		f >> mMatrix[i][j];
    	}
    }

    f.close();

}

void Compute::displayMatrix()
{
	cout<<"--------------------------------------------------"<<endl;


	for (int i = 0; i < m; ++i)
	{
		cout<<endl<<"\tAlternative "<<i+1<<" :   ";
		for (int j = 0; j < n; ++j)
		{
			cout<<mMatrix[i][j]<<"\t |";
		}
	}
}

void Compute::calculateCMatrix(CriteriaManager *cm)
{
}

void Compute::calculateDMatrix(CriteriaManager *cm)
{
}

void Compute::calculateSMatrix()
{
}

int Compute::outputResult()
{
	return 0;
}
