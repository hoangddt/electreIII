#include "../models/CriteriaManager.h"
#include <iostream>

#define TEST
#ifdef TEST

using namespace std;

int main(int argc, char const *argv[])
{
	CriteriaManager* cm = new CriteriaManager();

	int numOfCriteria = 3;
	Criteria *a[] = { new Criteria("C 1"), new Criteria("C2"), new Criteria("C3")};

	for (int i = 0; i < numOfCriteria; ++i)
	{
		cout<<"Loop: "<<i<<endl;
		cm->addCriteria(a[i]);
		cout<<"Size: "<<cm->size()<<endl;
		cm->display();
		cout<<"--------------"<<endl;
	}
	
	Criteria *temp = cm->getCriteria(1);
	temp->setName("Crit 2 changed");
	
	cm->display();
	delete cm;
	return 0;
}

#endif
