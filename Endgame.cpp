/* Endgame.cpp */

#include "project.h"

/* For each step given, check whether the game end. If so, change the flag isEnd */

void Endgame(int a, int b, bool& isEnd, int p[][15])

{



	/* judge whether player 1 wins */

	if (p[a][b] == -1)

	{

		/* check horizontal line*/

		for (int i = a - 4, j = b; i <= a; i++)

		{

			if (i >= 0 && i < 15 && p[i][j] == -1 && p[i + 1][j] == -1 && p[i + 2][j] == -1 && p[i + 3][j] == -1 && p[i + 4][j] == -1)

				isEnd = true;

		}



		/* check vertical line */

		for (int i = a, j = b - 4; j <= b; j++)

		{

			if (j >= 0 && j < 15 && p[i][j] == -1 && p[i][j + 1] == -1 && -1 == p[i][j + 2] && -1 == p[i][j + 3] && -1 == p[i][j + 4])

				isEnd = true;

		}



		/* check right diagonal line */

		for (int i = a - 4, j = b - 4; i <= a && j <= b; i++, j++)

		{

			if (i >= 0 && i < 15 && j > 0 && j < 16 && -1 == p[i][j] && -1 == p[i + 1][j + 1] && -1 == p[i + 2][j + 2] && -1 == p[i + 3][j + 3] && -1 == p[i + 4][j + 4])

				isEnd = true;

		}



		/* check left diagonal line */

		for (int i = a - 4, j = b + 4; i <= a && j >= b; i++, j--)

		{

			if (i >= 0 && i < 15 && j > 0 && j < 16 && -1 == p[i][j] && -1 == p[i + 1][j - 1] && -1 == p[i + 2][j - 2] && -1 == p[i + 3][j - 3] && -1 == p[i + 4][j - 4])

				isEnd = true;

		}

	}



	/* judge whether player 2 wins */

	if (p[a][b] == 1)

	{

		/* check horizontal line*/

		for (int i = a - 4, j = b; i <= a; i++)

		{

			if (i >= 0 && i < 15 && p[i][j] == 1 && p[i + 1][j] == 1 && p[i + 2][j] == 1 && p[i + 3][j] == 1 && p[i + 4][j] == 1)

				isEnd = true;

		}



		/* check vertical line */

		for (int i = a, j = b - 4; j <= b; j++)

		{

			if (j >= 0 && j < 15 && p[i][j] == 1 && p[i][j + 1] == 1 && 1 == p[i][j + 2] && 1 == p[i][j + 3] && 1 == p[i][j + 4])

				isEnd = true;

		}



		/* check right diagonal line */

		for (int i = a - 4, j = b - 4; i <= a && j <= b; i++, j++)

		{

			if (i >= 0 && i < 15 && j >= 0 && j < 15 && 1 == p[i][j] && 1 == p[i + 1][j + 1] && 1 == p[i + 2][j + 2] && 1 == p[i + 3][j + 3] && 1 == p[i + 4][j + 4])

				isEnd = true;

		}



		/* check left diagonal line */

		for (int i = a - 4, j = b + 4; i <= a && j >= b; i++, j--)

		{

			if (i >= 0 && i < 15 && j >= 0 && j < 15 && 1 == p[i][j] && 1 == p[i + 1][j - 1] && 1 == p[i + 2][j - 2] && 1 == p[i + 3][j - 3] && 1 == p[i + 4][j - 4])

				isEnd = true;

		}

	}



	return;

}



/* end of Endgame.cpp */
