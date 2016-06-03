#include <iostream>
#include "E3Controller.h"
#include <string>

using namespace std;

string alternativeFilePath = "data\\Alternatives.txt",
	   criteriaFilePath = "data\\Criterias.txt",
	   performanceMatrixFilePath = "data\\Matrix.txt",
	   PWQFilePath = "data\\PQW.txt";



E3Controller::E3Controller()
{
	mAM = new AlternativeManager();
	mCM = new CriteriaManager();

	mView = new View();
	mCompute = new Compute();

	mainLoop();
}

E3Controller::~E3Controller()
{
	delete mAM;
	delete mCM;
	delete mView;
	if (mCompute != NULL)
	{
		delete mCompute;
	}
}

void E3Controller::mainLoop()
{
	int opt;
	do
	{
		opt = mView->mainMenu();
		switch (opt)
		{
			case ALTERNATIVE_MENU:
				cout<<"ElaternativeMenu"<<endl;
				alternativeProcessing();
				break;
			case CRITERIA_MENU:
				cout<<"CriteriaMenu"<<endl;
				criteriaProcessing();
				break;
			case COMPUTE:
				cout<<"COMPUTE"<<endl;
				computeProcessing();
				break;
			case 4: cout<<"Thoat"<<endl;
		};
		
	}
	while (opt != 4);
}

void E3Controller::alternativeProcessing()
{
	int opt;
	do
	{
		opt = mView->alternativeMenu();
		switch (opt)
		{
			case 1:
				mAM->display();
				break;
			case 2:
				addAlternative();
				break;
			case 3:
				break;
		};
	} while (opt != 3);
}

void E3Controller::addAlternative()
{
	cout<<"Nhap Alternatives tu file: "<<alternativeFilePath<<endl;
	mAM->loadAlternativeFromFile(alternativeFilePath);

	cout<<"----> Nhap Alternative hoan tat"<<endl;
}

void E3Controller::editAlternative()
{
	cout<<"Edit Alternative, chua cai dat"<<endl;
}

void E3Controller::deleteAlternative()
{
	cout<<"DELETE Alternative, chua cai dat"<<endl;
}

void E3Controller::criteriaProcessing()
{
	int opt;
	do
	{
		opt = mView->criteriaMenu();
		switch (opt)
		{
			case 1:
				mCM->display();
				break;
			case 2:
				addCriteria();
				break;
			case 3:
				loadPQW();
				break;
			case 4:
				break;
		};
	} while (opt != 4);
}

void E3Controller::addCriteria()
{
	cout<<"Nhap Criteria tu file: "<<criteriaFilePath<<endl;
	mCM->loadCriteriaFromFile(criteriaFilePath);

	cout<<"----> Nhap criteria hoan tat"<<endl;
}

void E3Controller::loadPQW()
{
	cout<<"Load gia tri P, Q, W tu file: "<<PWQFilePath<<endl;
	mCM->loadPQWFromFile(PWQFilePath);

	cout<<"----> Load gia tri P, Q, W tu file hoan tat"<<endl;
}

void E3Controller::deleteCriteria()
{
	cout<<"DELETE Alternative, chua cai dat"<<endl;
}

void E3Controller::computeProcessing()
{

	int index;
	int opt;
	do
	{
		opt = mView->computeMenu();
		switch (opt)
		{
			case VIEW:
				mCompute->displayMatrix();
				break;
			case ADD:
				cout<<"Nhap Performance Matrix tu file: "<<performanceMatrixFilePath<<endl;
				mCompute->loadPerformanceMatrixFromFile(performanceMatrixFilePath);
				cout<<"----> Nhap performance Matrix hoan tat"<<endl;
				break;
			case 3:
				// tinh toan ma tran tuong thich C va D
				mCompute->calculateCMatrix(mCM);
				mCompute->calculateDMatrix(mCM);
				cout<<"\t== Da tinh xong C va D"<<endl;
				break;
			case 4:
				// tinh toan ma tran tin nhiem S
				mCompute->calculateSMatrix();
				cout<<"\t== Da tinh xong Ma tran S"<<endl;
				break;

			case 5:
				index = mCompute->outputResult(mAM);
				cout<<"----------";
				break;
				
			case 6:
				break;
		};
	} while (opt != 6);
}
