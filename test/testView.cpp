#include "../views/Views.h"
#include <iostream>


#ifdef TEST

using namespace std;

int main(int argc, char const *argv[])
{
	View *v = new View();

	int opt;
	do
	{
		opt = v->mainMenu();
		switch (opt)
		{
			case ALTERNATIVE_MENU:
				cout<<"ElaternativeMenu"<<endl;
				v->alternativeMenu();
				break;
			case CRITERIA_MENU:
				cout<<"CriteriaMenu"<<endl;
				v->criteriaMenu();
				break;
			case COMPUTE:
				cout<<"COMPUTE"<<endl;
				break;
			case EXIT: cout<<"Thoat"<<endl;
		};
		
	}
	while (opt != HALT);
	
	return 0;
}

#endif
