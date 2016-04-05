#include <iostream>
#include "controllers/E3Controller.h"


int main(int argc, char const *argv[])
{
	E3Controller *c = new E3Controller();

	delete c;
	return 0;
}