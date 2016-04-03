#include "../models/Alternative.h"
#include "../models/Criteria.h"
#include <iostream>



#ifdef TEST

using namespace std;

int main(int argc, char const *argv[])
{
	Criteria crit;
	Alternative alter;

	crit.input();
	alter.input();

	crit.display();
	alter.display();

	string c_name = crit.getName();
	string a_name = alter.getName();

	cout<<endl<<c_name<<endl;
	cout<<a_name;
	return 0;
}

#endif
