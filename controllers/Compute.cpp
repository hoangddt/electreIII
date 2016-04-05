#include "compute.h"
#include <iostream>

using namespace std;


Compute::Compute(int x, int y)
{
	w = x; // alternative
	h = y; // criteria

	mMatrix = new int*[w];

	for (int i = 0; i < w; ++i)
	{
		mMatrix[i] = new int[h];
	}
}

Compute::~Compute()
{
	for (int i = 0; i < w; ++i)
	{
		delete []mMatrix[i];
	}

	delete[] mMatrix;
}

void Compute::inputMatrix()
{
	cout<<"************** Nhap Matran g *********"<<endl;
	cout<<"\t| Criteria: ";
	for (int i = 0; i < h; ++i)
	{
		cout<<"Criteria "<<i+1<<"\t|";
	}

	cout<<endl<<"--------------------------------------------------"<<endl;

	for (int i = 0; i < w; ++i)
	{
		cout<<"\tAlternative "<<i+1<<" :   ";
		for (int j = 0; j < h; ++j)
		{
			cin>>mMatrix[i][j];
		}
	}
}

void Compute::displayMatrix()
{
	cout<<endl<<"************** Matran g *********"<<endl;
	cout<<"\t| Criteria: ";
	for (int i = 0; i < h; ++i)
	{
		cout<<"Criteria "<<i+1<<"\t|";
	}

	cout<<"--------------------------------------------------"<<endl;


	for (int i = 0; i < w; ++i)
	{
		cout<<endl<<"\tAlternative "<<i+1<<" :   ";
		for (int j = 0; j < h; ++j)
		{
			cout<<mMatrix[i][j]<<"\t |";
		}
	}
}
