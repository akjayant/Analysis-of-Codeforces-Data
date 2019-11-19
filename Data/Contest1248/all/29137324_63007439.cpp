#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 2e5+5, mod = 1e9+7;
int n;
int calc(string s, int i, int j)
{
	swap(s[i], s[j]);
	int idx = 0, mn = 0;
	int dif = 0;
	for(int i=0; i<n; i++)
	{
		dif += (s[i]=='(');
		dif -= (s[i]==')');
		if(dif < mn)
		{
			mn = dif;
			idx = i+1;
		}
	}
	dif = 0;
	int ret = 0;
	for(int i=idx; i<n+idx; i++)
	{
		int j = i%n;
		dif += (s[j]=='(');
		dif -= (s[j]==')');
		if(!dif) ret++;
	}
	return ret;
}
int main()
{
	string s;
	cin >> n >> s;
	int dif = 0;
	for(int i=0; i<n; i++) dif += (s[i]=='('), dif -= (s[i]==')');
	if(dif != 0) return cout << 0 << endl << "1 1" << endl, 0;
	int ans = calc(s, 0, 0);
	int x = 1, y = 1;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(s[i] == s[j]) continue;
			int tmp = calc(s, i, j);
			if(tmp > ans)
			{
				ans = tmp;
				x = i+1;
				y = j+1;
			}
		}
	}
	cout << ans << endl << x << " " << y << endl;;
}