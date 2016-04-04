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
	cout<<"ELECTRE III Progran: "<<endl;
	cout<<"  1: Thao tac voi Alternative"<<endl;
	cout<<"  2: Thao tac voi Criteriaria"<<endl;
	cout<<"  3: Tinh toan"<<endl;
	cout<<"  4: Thoat"<<endl;
	cout<<"Moi Nhap lua chon: ";
	
	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}

int View::alternativeMenu()
{
	cout<<"Thao tac voi Alternative"<<endl;
	cout<<"  1: Xem toan bo Alternative"<<endl;
	cout<<"  2: Them moi Alternative"<<endl;
	cout<<"  3: Sua Alternative"<<endl;
	cout<<"  4: Xoa Alternative"<<endl;
	cout<<"  5: Thoat ra MainMenu"<<endl;
	cout<<"Moi Nhap lua chon: ";

	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}

int View::criteriaMenu()
{
	cout<<"Thao tac voi Criteria"<<endl;
	cout<<"  1: Xem toan bo Criteria"<<endl;
	cout<<"  2: Them moi Criteria"<<endl;
	cout<<"  3: Sua Criteria"<<endl;
	cout<<"  4: Xoa Criteria"<<endl;
	cout<<"  5: Thoat ra MainMenu"<<endl;
	cout<<"Moi Nhap lua chon: ";
	
	int opt;
	cin>>opt;
	cout<<endl;
	return opt;
}
