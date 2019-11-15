#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<functional>
using namespace std;

#define INF 1234567890
#define ll long long
#define MOD 1000000007

string s;
int dp[100101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	if (s.size() == 1)
	{
		cout << 1;
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'w' || s[i] == 'm')
		{
			cout << 0;
			return 0;
		}
	}

	dp[0] = 1;
	if ((s[0] == 'u' && s[1] == 'u') || (s[0] == 'n' && s[1] == 'n'))
		dp[1] = 2;
	else
		dp[1] = 1;

	for (int i = 2; i < s.size(); i++)
	{
		if ((s[i - 1] == 'u' && s[i] == 'u') || (s[i - 1] == 'n' && s[i] == 'n'))
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		else
			dp[i] = dp[i - 1];
	}
	cout << dp[(int)s.size() - 1];
	return 0;
}