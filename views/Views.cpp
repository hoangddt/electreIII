#include <iostream>
#include "Views.h"
#include "Option.h"

using namespace std;

View::View()
{
}

View::~View()
{
}

int View::mainMenu()
{
	cout<<endl<<"*********** ELECTRE III Program: ***********"<<endl;
	cout<<"\t+-------------------------------+"<<endl;
	cout<<"\t|  1: Thao tac voi Alternative\t|"<<endl;
	cout<<"\t|  2: Thao tac voi Criteriaria\t|"<<endl;
	cout<<"\t|  3: Tinh toan               \t|"<<endl;
	cout<<"\t|  4: Thoat                   \t|"<<endl;
	cout<<"\t+-------------------------------+"<<endl;
	cout<<"====>Moi Nhap lua chon: ";
	
	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}

int View::alternativeMenu()
{
	cout<<endl<<"*********** Thao tac voi Alternative ***********"<<endl;
	cout<<"\t+-------------------------------+"<<endl;
	cout<<"\t|  1: Xem toan bo Alternative \t|"<<endl;
	cout<<"\t|  2: Them moi Alternative    \t|"<<endl;
	cout<<"\t|  3: Thoat ra MainMenu       \t|"<<endl;
	cout<<"\t+-------------------------------+"<<endl;
	cout<<"====>Moi Nhap lua chon: ";

	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}

int View::criteriaMenu()
{
	cout<<endl<<"*********** Thao tac voi Criteria ***********"<<endl;
	cout<<"\t+-----------------------------------+"<<endl;
	cout<<"\t|  1: Xem toan bo Criteria        \t|"<<endl;
	cout<<"\t|  2: Them moi Criteria           \t|"<<endl;
	cout<<"\t|  3: Load gia tri p, q va weight \t|"<<endl;
	cout<<"\t|  4: Thoat ra MainMenu           \t|"<<endl;
	cout<<"\t+-----------------------------------+"<<endl;
	cout<<"====>Moi Nhap lua chon: ";
	
	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}

int View::computeMenu()
{
	cout<<endl<<"*********** Xu Ly Tinh Toan ***********"<<endl;
	cout<<"\t+-----------------------------------------------+"<<endl;
	cout<<"\t|  1: Xem Matran           		\t|"<<endl;
	cout<<"\t|  2: Nhap Matran          		\t|"<<endl;
	cout<<"\t|  3: Tinh toan ma tran tuong thich C va D \t|"<<endl;
	cout<<"\t|  4: Tinh toan ma tran tin nhiem          \t|"<<endl;
	cout<<"\t|  5: Xep hang giam dan    		\t|"<<endl;
	cout<<"\t|  6: Thoat ra MainMenu    		\t|"<<endl;
	cout<<"\t+-----------------------------------------------+"<<endl;
	cout<<"====>Moi Nhap lua chon: ";
	
	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}
