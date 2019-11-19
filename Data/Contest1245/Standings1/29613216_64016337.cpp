#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
	const int N = 10;
	int H[N + 1][N + 1];
	double F[N + 1][N + 1];
	
	void work()
	{
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &H[i][j]);
		for (int i = 1; i <= N; i++)
			if (i & 1)
			{
				for (int j = 1; j <= N; j++)
					if (i == 1 && j == 1)
						F[i][j] = 0; 
					else
					{
						int x = i, y = j, t = 0;
						double s = 0;
						for (int c = 1; c <= 6; c++)
						{
							if (x == 1 && y == 1)
								t++;
							else
							{
								if ((x & 1) ? y == 1 : y == N)
									x--;
								else if (x & 1)
									y--;
								else
									y++;
								s += min(F[x][y], F[x - H[x][y]][y]) / 6;
							}
						}
						F[i][j] = (s + 1) * 6 / (6 - t);
					}
			}
			else
			{
				for (int j = N; j >= 1; j--)
					if (i == 1 && j == 1)
						F[i][j] = 0; 
					else
					{
						int x = i, y = j, t = 0;
						double s = 0;
						for (int c = 1; c <= 6; c++)
						{
							if (x == 1 && y == 1)
								t++;
							else
							{
								if ((x & 1) ? y == 1 : y == N)
									x--;
								else if (x & 1)
									y--;
								else
									y++;
								s += min(F[x][y], F[x - H[x][y]][y]) / 6;
							}
						}
						F[i][j] = (s + 1) * 6 / (6 - t);
					}
			}
		printf("%.10lf\n", F[N][1]);
	}
}

int main()
{
	jumpmelon::work();
	return 0;
}