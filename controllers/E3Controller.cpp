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
			case 1:
			// nhap du lieu
				inputProcessing();
				break;
			case 2:
				viewDataProcessing();
				break;
			case 3:
				computeProcessing();
				break;
			case 4: cout<<"Good Bye!"<<endl;
		};
		
	}
	while (opt != 4);
}

void E3Controller::inputProcessing()
{
	int opt;
	do
	{
		opt = mView->inputMenu();
		switch (opt)
		{
			case 1:
				addAlternative();
				break;
			case 2:
				addCriteria();
				break;
			case 3:
				loadPQW();
				break;
			case 4:
				cout<<"Nhap Performance Matrix tu file: "<<performanceMatrixFilePath<<endl;
				mCompute->loadPerformanceMatrixFromFile(performanceMatrixFilePath);
				cout<<"----> Nhap performance Matrix hoan tat"<<endl;
				break;
		};
	} while (opt != 5);
}

void E3Controller::addAlternative()
{
	cout<<"Nhap Alternatives tu file: "<<alternativeFilePath<<endl;
	mAM->loadAlternativeFromFile(alternativeFilePath);

	cout<<"----> Nhap Alternative hoan tat"<<endl;
}

void E3Controller::viewDataProcessing()
{
	int opt;
	do
	{
		opt = mView->viewMenu();
		switch (opt)
		{
			case 1:
				mAM->display();
				break;
			case 2:
				mCM->display();
				break;
			case 3:
				mCompute->displayMatrix();
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

void E3Controller::computeProcessing()
{
	// tinh toan ma tran tuong thich C va D
	mCompute->calculateCMatrix(mCM);
	mCompute->calculateDMatrix(mCM);

	// tinh toan ma tran tin nhiem S
	mCompute->calculateSMatrix();

	// xuat ket qua cuoi cung
	mCompute->outputResult(mAM);
}
