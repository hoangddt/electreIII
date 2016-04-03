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

	void setID(string id);
	string getID();

	void display();
	void input();
private:
	string mName;
	string mDesc;
	string mID;
};