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
	cout<<endl<<"        *********** ELECTRE III Program: ********"<<endl;
	cout<<"\t+---------------------------------------+"<<endl;
	cout<<"\t|  1: Nhap Du Lieu                   \t|"<<endl;
	cout<<"\t|  2: Xem Du Lieu                    \t|"<<endl;
	cout<<"\t|  3: Tinh toan xep hang lua chon    \t|"<<endl;
	cout<<"\t|  4: Thoat                          \t|"<<endl;
	cout<<"\t+---------------------------------------+"<<endl;
	cout<<"====>Moi Nhap lua chon: ";
	
	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}

int View::inputMenu()
{
	cout<<endl<<"        **** Nhap Du Lieu Cho chuong trinh ******"<<endl;
	cout<<"\t+---------------------------------------+"<<endl;
	cout<<"\t|  1: Nhap Alternative               \t|"<<endl;
	cout<<"\t|  2: Nhap Criteria                  \t|"<<endl;
	cout<<"\t|  3: Nhap P, Q, va weight           \t|"<<endl;
	cout<<"\t|  4: Nhap performance matrix        \t|"<<endl;
	cout<<"\t|  5: Thoat ra main menu             \t|"<<endl;
	cout<<"\t+---------------------------------------+"<<endl;
	cout<<"====>Moi Nhap lua chon: ";

	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}

int View::viewMenu()
{
	cout<<endl<<"*********** Xem du lieu cua chuong trinh ***********"<<endl;
	cout<<"\t+--------------------------------------+"<<endl;
	cout<<"\t|  1: Xem toan bo Alternative        \t|"<<endl;
	cout<<"\t|  2: Xem toan bo Criteria           \t|"<<endl;
	cout<<"\t|  3: Xem Performance Matrix         \t|"<<endl;
	cout<<"\t|  4: Thoat ra MainMenu              \t|"<<endl;
	cout<<"\t+--------------------------------------+"<<endl;
	cout<<"====>Moi Nhap lua chon: ";
	
	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}
