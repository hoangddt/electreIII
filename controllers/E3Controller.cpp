#include <iostream>
#include "E3Controller.h"

using namespace std;

E3Controller::E3Controller()
{
	mAM = new AlternativeManager();
	mCM = new CriteriaManager();

	mView = new View();
	mCompute = NULL;

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
			case EXIT: cout<<"Thoat"<<endl;
		};
		
	}
	while (opt != HALT);
}

void E3Controller::alternativeProcessing()
{
	int opt;
	do
	{
		opt = mView->alternativeMenu();
		switch (opt)
		{
			case VIEW:
				mAM->display();
				break;
			case ADD:
				addAlternative();
				break;
			case EDIT:
				editAlternative();
				break;
			case DELETE:
				deleteAlternative();
				break;
			case EXIT:
				break;
		};
	} while (opt != EXIT);
}

void E3Controller::addAlternative()
{
	int next = 0;
	do
	{
		cout<<"=== Nhap thong tin cho Alternative: "<<endl;
		Alternative *a = new Alternative();
		a->input();
		mAM->addAlternative(a);

		cout<<"=== Tiep tuc? (1/0): ";
		cin>>next;
		cout<<endl;
	}
	while (next);
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
			case VIEW:
				mCM->display();
				break;
			case ADD:
				addCriteria();
				break;
			case EDIT:
				editCriteria();
				break;
			case DELETE:
				deleteCriteria();
				break;
			case EXIT:
				break;
		};
	} while (opt != EXIT);
}

void E3Controller::addCriteria()
{
	int next = 0;
	do
	{
		cout<<"=== Nhap thong tin cho Criteria: "<<endl;
		Criteria *a = new Criteria();
		a->input();
		mCM->addCriteria(a);

		cout<<"=== Tiep tuc? (1/0): ";
		cin>>next;
		cout<<endl;
	}
	while (next);
}

void E3Controller::editCriteria()
{
	cout<<"Edit Alternative, chua cai dat"<<endl;
}

void E3Controller::deleteCriteria()
{
	cout<<"DELETE Alternative, chua cai dat"<<endl;
}

void E3Controller::computeProcessing()
{
	int w = mAM->size(),
		h = mCM->size();

	if (mCompute == NULL)
		mCompute = new Compute(w, h);

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
				mCompute->inputMatrix();
				break;
			case EDIT:
				
				break;
			case DELETE:
				
				break;
			case EXIT:
				break;
		};
	} while (opt != EXIT);
}