#pragma once
#include <string>

using namespace std;

class Criteria
{
public:
	Criteria();
	Criteria(string name);
	~Criteria();

	void setName(string name);
	string getName();

	void setID(int id);
	int getID();
	
	float Weight;
	float Vecto;
	float P;
	float Q;

	void display();
private:
	string mName;
	string mDesc;
	int mID;
};
