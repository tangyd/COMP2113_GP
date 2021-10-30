/* validinput.cpp */
#include <iostream>
#include "project.h"

using namespace std;

bool Validinput(int a, int b, int p[][15])
{
	if (a <= 15 && b <= 15 && p[a][b] == 0)
		return true;
	else
		return false;
}

/* end of validinput.cpp */
