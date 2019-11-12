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
const int mod = 1e9 + 7;
long long pow(long long a, long long b, long long _mod)
{
	long long ans = 1, base = a;
	while (b != 0)
	{
		if ((b & 1) != 0)
		{
			ans *= base;
			ans %= _mod;
		}
		base *= base;
		base %= _mod;
		b >>= 1;
	}
	return ans;
}
int arr[310][310];
int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i & 1)
				arr[i][j] = (i - 1) * N + j;
			else
				arr[i][N - j + 1] = (i - 1) * N + j;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << arr[j][i] << " ";
		}
		cout << "\n";
	}

}
