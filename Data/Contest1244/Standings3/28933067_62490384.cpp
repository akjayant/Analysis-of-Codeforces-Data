#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<cmath>
#include<map>
#include<set>
#include<deque>
using namespace std;
const int maxn = 1e5 + 10;
long long val[maxn][3];
vector<int>G[maxn];
int arr[maxn];
const int ratio[6][3] = { {0,1,2},{1,0,2},{2,0,1},{0,2,1},{1,2,0},{2,1,0} };
int ans_arr[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> val[j][i];
		}
	}
	for (int i = 1; i <= N - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int st;
	for (int i = 1; i <= N; i++)
	{
		if (G[i].size() == 1)
		{
			st = i;
		}
		if (G[i].size() >= 3)
		{
			cout << -1 << "\n";
			return 0;
		}
	}
	arr[0] = st;
	arr[1] = G[st][0];
	for (int i = 2; i < N; i++)
	{
		for (int to : G[arr[i - 1]])
		{
			if (to == arr[i - 2])
				continue;
			arr[i] = to;
		}
	}
	long long ans = INT64_MAX;
	int ans1 = 0;
	for (int i = 0; i < 6; i++)
	{
		long long temp = 0;
		for (int j = 0; j < N; j++)
		{
			temp += val[arr[j]][ratio[i][j % 3]];
		}
		if (temp < ans)
		{
			ans = temp;
			ans1 = i;
		}
	}
	cout << ans << "\n";
	for (int j = 0; j < N; j++)
	{
		ans_arr[arr[j]] = ratio[ans1][j % 3] + 1;
	}
	for (int i = 1; i <= N; i++)
	{
		cout << ans_arr[i] << " ";
	}
}
