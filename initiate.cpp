/* initiate.cpp */
#include <cstdlib>
#include <ctime>

void initiate(int p[][15], bool &isEnd, bool &isNew, int &n, int &turn)
{
	for (int i = 0; i < 15; i++)
		for (int j = 0; j < 15; j++)
			p[i][j] = 0;
	isNew = true;
	isEnd = false;
	srand(time(NULL));
	n = rand() % 2;
	turn = 0;
}

/* End of initiate.cpp */
