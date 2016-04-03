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

	void setID(string id);
	string getID();
	
	float Weight;
	float Vecto;
	float P;
	float Q;

	void display();
	void input();
private:
	string mName;
	string mDesc;
	string mID;
};