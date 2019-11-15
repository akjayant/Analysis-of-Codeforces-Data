#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <functional>
using namespace std;
#pragma warning(disable:4996)
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const long long LINF = 1e18 + 1;
typedef long long ll;
typedef pair<int, int> P;

vector<int> vt[301];

int main()
{
	int N;
	scanf("%d", &N);
	int idx = 0;
	bool flag = false;
	for (int i = 1; i <= N * N; i++)
	{
		if (!flag)
		{
			vt[idx++].push_back(i);
			if (idx == N)
			{
				flag = true;
				idx--;
			}
		}
		else
		{
			vt[idx--].push_back(i);
			if (idx == -1)
			{
				flag = false;
				idx++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", vt[i][j]);
		}
		puts("");
	}
	return 0;
}