#include <cstdio>
#include <vector>

const int MAX_N = 3e2 + 5;

int n;
std::vector<int> ans[MAX_N];

int main()
{
	scanf("%d", &n);
	for (int i = n * n, j = 0, k = 1; i > 0; j += k)
	{
		if (j >= 0 && j < n)
			ans[j].push_back(i--);
		if (j == n) k = -1;
		else if (j < 0) k = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j : ans[i])
			printf("%d ", j);
		printf("\n");
	}
	return 0;
}
