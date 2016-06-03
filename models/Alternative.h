#include <string>

using namespace std;



class Alternative
{
public:
	Alternative();
	Alternative(string name);
	~Alternative();
	
	void setName(string name);
	string getName();

	void setID(int id);
	int getID();

	void display();
	void input();
private:
	string mName;
	string mDesc;
	int mID;
};