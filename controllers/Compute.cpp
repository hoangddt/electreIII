#include "compute.h"
#include <iostream>
#include <fstream>

using namespace std;

void alloc2DArray(float** &arr, int w, int h)
{
	arr = new float*[w];

	for (int i = 0; i < w; ++i)
	{
		arr[i] = new float[h];
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
	cout<<"----------Performance Matrix------------------"<<endl;


	for (int i = 0; i < m; ++i)
	{
		cout<<endl<<"\tAlternative "<<i+1<<" :   ";
		for (int j = 0; j < n; ++j)
		{
			cout<<mMatrix[i][j]<<"\t |";
		}
	}

	// cout<<endl<<"-----C Matrix------------------------"<<endl;
	// for (int i = 0; i < m; ++i)
	// {
	// 	for (int j = 0; j < m; ++j)
	// 	{
	// 		cout<<mCMatrix[i][j]<<"\t |";
	// 	}
	// 	cout<<endl;
	// }
}

void Compute::calculateCMatrix(CriteriaManager *cm)
{
	// m: number of alternative
	alloc2DArray(mCMatrix, m, m);
	int numberOfCriteria = cm->size();
	float *cTemp = new float[numberOfCriteria];

	float tuso = 0,
		  mauso = 0;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == j)
			{
				mCMatrix[i][j] = 1;
				continue;
			}

			for (int k = 0; k < numberOfCriteria; ++k)
			{
				if (mMatrix[i][k] + cm->Q[k] >= mMatrix[j][k])
					cTemp[k] = 1;
				else if (mMatrix[j][k] >= mMatrix[i][k] + cm->P[k])
					cTemp[k] = 0;
				else
					cTemp[k] = (mMatrix[i][k] + cm->P[k] - mMatrix[j][k]) / (cm->P[k] - cm->Q[k]);
				
				// cout<<"i - j - k - cTemp: "<<i<<", "<<j<<", "<<k<<", "<<cTemp[k]<<endl;
			}
			
			for (int l = 0; l < numberOfCriteria; ++l)
			{
				tuso += cm->W[l]*cTemp[l];
				mauso += cm->W[l];
			}

			mCMatrix[i][j] = tuso / mauso;
			// cout<<"tuso - mauso - matrix[i][j]: "<<tuso<<", "<<mauso<<", "<<mCMatrix[i][j]<<endl;
			// reset for next loop
			tuso = mauso = 0;
		}
	}

	delete []cTemp;

}

void Compute::calculateDMatrix(CriteriaManager *cm)
{
	// If no veto threshold (vi) is specified Di(a,b) = 0 for all pairs of alternatives.
	alloc2DArray(mDMatrix, m, m);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mDMatrix[i][j] = 0;
		}
	}
}

void Compute::calculateSMatrix()
{
	// If no veto thresholds (vi) are specified S(a,b) = C(a,b) for all pairs of alternatives.
	alloc2DArray(mSMatrix, m, m);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			mSMatrix[i][j] = mCMatrix[i][j];
		}
	}
}

int Compute::outputResult(AlternativeManager *am)
{
	float lamda_max, lamda;

	lamda_max = mSMatrix[0][0];

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mSMatrix[i][j] > lamda_max)
				lamda_max = mSMatrix[i][j];
		}
	}

	lamda = lamda_max - (0.3 - 0.15*lamda_max);

	int *qualification = new int[m];

	for (int i = 0; i < m; ++i)
	{
		int l_strength = 0, l_weakness = 0;
		for (int j = 0; j < m; ++j)
		{
			if (mSMatrix[i][j] > lamda)
				l_strength++;
			if ( (1 - (0.3 - 0.15 * lamda)) * mSMatrix[i][j] > mSMatrix[j][i] )
				l_weakness++;
		}

		qualification[i] = l_strength - l_weakness;
	}

	int *index = new int[m];
	for (int i = 0; i < m; ++i)
	{
		index[i] = i;
	}
	// sap xep mang qualification, so nao lon nhat la tot nhat

	for (int i = m - 1; i > 0; i--)
	{
		for (int j = 0; j < i; ++j)
		{
			if (qualification[j] < qualification[j + 1])
			{
				int temp = qualification[j];
				qualification[j] = qualification[j + 1];
				qualification[j + 1] = temp;

				temp = index [j];
				index [j] = index[j + 1];
				index[j + 1] = temp;
			}
		}
	}

	// cout<<"Ket qua lua chon, xep theo thu tu giam dan: "<<endl;
	cout<<"\t\t+ Lua chon tot nhat la: "<<endl;
	cout<<"\t\t\t1: "<<am->getAlternative(index[0])->getName()<<endl;
	cout<<"\t\t+Cac lua chon khac theo thu tu giam dan: "<<endl;

	for (int i = 1; i < m; ++i)
	{
		cout<<"\t\t\t"<<i+1<<": "<<am->getAlternative(index[i])->getName()<<endl;
	}
	delete []qualification;
	delete []index;

	return 0;
}
