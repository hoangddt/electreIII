#include "../models/AlternativeManager.h"
#include <iostream>


#ifdef TEST

using namespace std;

int main(int argc, char const *argv[])
{
	AlternativeManager* am = new AlternativeManager();

	int numOfAlternative = 3;
	Alternative *a[] = { new Alternative("Alter 1"), new Alternative("A2"), new Alternative("A3")};

	for (int i = 0; i < numOfAlternative; ++i)
	{
		cout<<"Loop: "<<i<<endl;
		am->addAlternative(a[i]);
		cout<<"Size: "<<am->size()<<endl;
		am->display();
		cout<<"--------------"<<endl;
	}
	
	Alternative *temp = am->getAlternative(1);
	temp->setName("Alter2 changed");
	
	am->display();

	delete am;
	return 0;
}

#endif
