/* computer_input.cpp */

#include <cstdlib>

#include "project.h"



void computer_input(int& a, int& b, int c, int d, int p[][15], int &turn)

{

	if (c == -1 && d == -1)

	{

		a = 7;

		b = 7;

	}

	else

	{

		/* check whether the computer holds black or white */

		int t;

		if (turn % 2 != 0)

			t = 1;

		else

			t = -1;



		/* check whether there is four in a line */

		for (int i = c - 3, j = d; i <= c; i++)

		{

			if (i >= 0 && i < 15 && p[i][j] == t && p[i + 1][j] == t && p[i + 2][j] == t && p[i + 3][j] == t)

			{

				if (i + 4 < 15 && p[i + 4][j] == 0)

				{

					a = i + 4;

					b = j;

					return;

				}

				else if (i - 1 >= 0 && p[i - 1][j] == 0)

				{

					a = i - 1;

					b = j;

					return;

				}

				else

				{

					continue;

				}

			}

		}

		for (int i = c, j = d - 3; j <= d; j++)

		{

			if (j >= 0 && j < 15 && p[i][j] == t && p[i][j + 1] == t && p[i][j + 2] == t && p[i][j + 3] == t)

			{

				if (j + 4 < 15 && p[i][j + 4] == 0)

				{

					a = i;

					b = j + 4;

					return;

				}

				else if (j - 1 >= 0 && p[i][j - 1] == 0)

				{

					a = i;

					b = j - 1;

					return;

				}

				else

				{

					continue;

				}

			}

		}

		for (int i = c - 3, j = d - 3; i <= c && j <= d; i++, j++)

		{

			if (i >= 0 && i < 15 && j >= 0 && j < 15 && t == p[i][j] && t == p[i + 1][j + 1] && t == p[i + 2][j + 2] && t == p[i + 3][j + 3])

			{

				if (j + 4 < 15 && i + 4 < 15 && p[i + 4][j + 4] == 0)

				{

					a = i + 4;

					b = j + 4;

					return;

				}

				else if (j - 1 >= 0 && i - 1 >= 0 && p[i][j - 1] == 0)

				{

					a = i - 1;

					b = j - 1;

					return;

				}

				else

				{

					continue;

				}

			}



		}

		for (int i = c - 3, j = d + 3; i <= c && j >= d; i++, j--)

		{

			if (i >= 0 && i < 15 && j >= 0 && j < 15 && t == p[i][j] && t == p[i + 1][j - 1] && t == p[i + 2][j - 2] && t == p[i + 3][j - 3])

			{

				if (j - 4 >= 0 && i + 4 < 15 && p[i + 4][j - 4] == 0)

				{

					a = i + 4;

					b = j - 4;

					return;

				}

				else if (j + 1 < 15 && i - 1 >= 0 && p[i - 1][j + 1] == 0)

				{

					a = i - 1;

					b = j + 1;

					return;

				}

				else

				{

					continue;

				}

			}

		}



		/* check whether 3 in a line */

		for (int i = c - 2, j = d; i <= c; i++)

		{

			if (i >= 0 && i < 15 && p[i][j] == t && p[i + 1][j] == t && p[i + 2][j] == t)

			{

				if (i + 3 < 15 && p[i + 3][j] == 0)

				{

					a = i + 3;

					b = j;

					return;

				}

				else if (i - 1 >= 0 && p[i - 1][j] == 0)

				{

					a = i - 1;

					b = j;

					return;

				}

				else

				{

					continue;

				}

			}

		}

		for (int i = c, j = d - 2; j <= d; j++)

		{

			if (j >= 0 && j < 15 && p[i][j] == t && p[i][j + 1] == t && p[i][j + 2] == t)

			{

				if (j + 3 < 15 && p[i][j + 3] == 0)

				{

					a = i;

					b = j + 3;

					return;

				}

				else if (j - 1 >= 0 && p[i][j - 1] == 0)

				{

					a = i;

					b = j - 1;

					return;

				}

				else

				{

					continue;

				}

			}

		}

		for (int i = c - 2, j = d - 2; i <= c && j <= d; i++, j++)

		{

			if (i >= 0 && i < 15 && j >= 0 && j < 15 && t == p[i][j] && t == p[i + 1][j + 1] && t == p[i + 2][j + 2])

			{

				if (j + 3 < 15 && i + 3 < 15 && p[i + 3][j + 3] == 0)

				{

					a = i + 3;

					b = j + 3;

					return;

				}

				else if (j - 1 >= 0 && i - 1 >= 0 && p[i][j - 1] == 0)

				{

					a = i - 1;

					b = j - 1;

					return;

				}

				else

				{

					continue;

				}

			}



		}

		for (int i = c - 2, j = d + 2; i <= c && j >= d; i++, j--)

		{

			if (i >= 0 && i < 15 && j >= 0 && j < 15 && t == p[i][j] && t == p[i + 1][j - 1] && t == p[i + 2][j - 2])

			{

				if (j - 3 >= 0 && i + 3 < 15 && p[i + 3][j - 3] == 0)

				{

					a = i + 3;

					b = j - 3;

					return;

				}

				else if (j + 1 < 15 && i - 1 >= 0 && p[i - 1][j + 1] == 0)

				{

					a = i - 1;

					b = j + 1;

					return;

				}

				else

				{

					continue;

				}

			}

		}

	}

	/* random put stone if no case matched */

	if (c - 1 >= 0 && p[c - 1][d] == 0)

	{

		a = c - 1;

		b = d;

		return;

	}

	if (c + 1 < 15 && p[c + 1][d] == 0)

	{

		a = c + 1;

		b = d;

		return;

	}

	if (d - 1 >= 0 && p[c][d - 1] == 0)

	{

		a = c;

		b = d - 1;

		return;

	}

	if (d + 1 < 15 && p[c][d + 1] == 0)

	{

		a = c;

		b = d + 1;

		return;

	}

	if (d - 1 >= 0 && c + 1 < 15 && p[c + 1][d - 1] == 0)

	{

		a = c + 1;

		b = d - 1;

		return;

	}

	if (d - 1 >= 0 && c - 1 >= 0 && p[c - 1][d - 1] == 0)

	{

		a = c - 1;

		b = d - 1;

		return;

	}

	if (c - 1 >= 0 && d + 1 < 15 && p[c - 1][d + 1] == 0)

	{

		a = c - 1;

		b = d + 1;

		return;

	}

	if (d + 1 < 15 && c + 1 < 15 && p[c + 1][d + 1] == 0)

	{

		a = c + 1;

		b = d + 1;

		return;

	}

	int m = 0, n = 0;

	while (p[m][n] != 0)

	{

		m = rand() % 15;

		n = rand() % 15;

	}

	a = m;

	b = n;

	return;

}
