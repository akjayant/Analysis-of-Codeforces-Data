#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
#define int ll
const int mod = 1000000007;
int fibo[101010];
vector <int> tonum;
string str;
int32_t main()
{
	fibo[1] = 1;
	fibo[2] = 2;
	for (int i = 3; i<101010; i++)
		fibo[i] = (fibo[i-1] + fibo[i-2]) % mod;
	cin >> str;
	for (int i = 0; i<str.size(); i++)
	{
		if (str[i] == 'w' || str[i] == 'm')
		{
			cout << 0 << '\n'; return 0;
		}
		if (tonum.empty())
			tonum.push_back(1);
		else
		{
			if (str[i] == 'w' || str[i] == 'm')
			{
				cout << 0 << '\n'; return 0;
			}
			else
			{
				if (str[i] == str[i-1])
				{
					if (str[i] == 'u' || str[i] =='n')
						tonum.back()+=1;
					else
						tonum.push_back(1);
				}
				else
					tonum.push_back(1);
			}
		}
	}
	int ans = 1;
	for (auto it:tonum)
	{
		ans *= fibo[it];
		ans %= mod;
	}
	cout << ans << '\n';
}