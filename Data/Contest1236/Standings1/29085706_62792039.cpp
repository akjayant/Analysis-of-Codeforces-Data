#include <iostream>
#include <vector>
using namespace std;
vector<int> ans[500];
int main()
{
	int n;
	scanf("%d", &n);
	int k = 0;
	int d = 0;
	for (int t = 1; t <= n * n;)
	{
		if (d == 0)
		{
			for (int i = 0; i < n; i++)
			{
				ans[i].push_back(t);
				t++;
			}
			d = 1;
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				ans[i].push_back(t);
				t++;
			}
			d = 0;
		}
	}
	for (int i = 0; i < n ;i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}