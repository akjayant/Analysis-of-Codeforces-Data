#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

string s;

ll c(int x, int y)
{
	ll ans = 1;
	for(int i = x; (x - i + 1) <= y; i--)
		ans *= i, ans %= mod;
	for(int i = y; i >= 1; i--)
		ans /= i;
	return ans;
}

ll sum[100005];

int main()
{
	cin >> s;
	ll ans = 1;
	sum[1] = 1, sum[2] = 2, sum[3] = 3;
	for(int i = 3; i < s.size(); i++) sum[i] = (sum[i - 1] + sum[i - 2]) %  mod;
	for(int i = 0; i < s.size(); i++)
	{
		int cnt = 0;
		if(s[i] == 'u' || s[i] == 'n')
		{
			cnt = 1;
			while(s[i + 1] == s[i] && i + 1 < s.size()) cnt++, i++;
			ans *= sum[cnt], ans %= mod;
		}
		if(s[i] == 'w' || s[i] == 'm') ans = 0;
	}
	cout << ans << endl;
	return 0;
}