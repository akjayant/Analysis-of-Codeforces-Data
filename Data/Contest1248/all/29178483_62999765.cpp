#include<bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int mmod = 1e9 + 7;
char s[maxn];
int tot[maxn];
int main()
{
	int len;
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> len >> s;
	int p = 0, q = 0;
	for(int i = 0; i < len; i ++)
	{
		if(s[i] == '(') p ++;
		else q ++;
	}
	if(p != q)
	{
		cout <<"0\n1 1\n";
		return 0;
	}
	int ans = 0, x = 1, y = 1;
	for(int i = 0; i < len - 1; i ++)
	{
		for(int j = i; j < len; j ++)
		{
			swap(s[i], s[j]);
			tot[0] = (s[0] == '(' ? 1 : -1);
			int mmin = tot[0];
			for(int i = 1; i < len; i ++)
			{
				tot[i] = tot[i - 1];
				tot[i] += (s[i] == '(' ? 1 : -1);
				mmin = min(mmin, tot[i]);
			}
			int nu = 0;
			for(int i = 0; i < len; i ++)
			{
				if(tot[i] == mmin) nu ++;
			}
			if(nu > ans)
			{
				ans = nu;
				x = i; y = j;
			}
			swap(s[i], s[j]);
		}
	}
	cout << ans<<"\n"<<x + 1<<" "<<y + 1<<"\n";
	return 0;
}