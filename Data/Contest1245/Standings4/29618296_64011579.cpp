#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <list>
#include<set>
using namespace std;

#define FOR(n) for(int i=0;i<n;++i)
#define FORj(n) for(int j=0;j<n;++j)
#define pb push_back
#define ll long long
#define vecI vector<int> 
#define vecII vector<vector<int>>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
ll f[100009];
ll p = 1e9 + 7;
int main()
{
	ll k = 0,otv=1;
	f[0] = 1;
	f[1] = 1;
	for (int i = 2; i <= 1e5 + 7; ++i)f[i] = (f[i - 1] + f[i - 2]) % p;
	string s;
	cin >> s;
	FOR(size(s))
		if (s[i] == 'm' || s[i]=='w')
		{
			cout << 0;
			return 0;
		}
		else if (s[i] == 'n')
		{
			if (i > 0)if (s[i - 1] == 'u')
			{
				otv = (otv*f[k]) % p;
				k = 0;
			}
			k++;
		}
		else if (s[i] == 'u')
		{
			if (i > 0)if (s[i - 1] == 'n')
			{
				otv = (otv*f[k]) % p;
				k = 0;
			}
			k++;
		}
		else
		{
			otv = (otv*f[k]) % p;
			k = 0;
		}
	otv = (otv*f[k]) % p;
	cout << otv;
}