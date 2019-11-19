#include <bits/stdc++.h>
 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define ll long long
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
#define en "\n"
#define FOR(i, j, n) for(int j = i; j < n; ++j)
#define forn(i, j, n) for(int j = i; j <= n; ++j)
#define nfor(i, j, n) for(int j = n; j >= i; --j)
#define all(v) v.begin(), v.end()
 
using namespace std;

int block;
const ll maxn=2e5+100,inf=1e18,LOG=20,mod=1e9 + 3;

#define int ll

main()
{
	int n, ans;
	cin >> n;
	ans = 0;
	forn(2, i, n)
	{
		if(i * i > n) break;
		if(n % i == 0)
		{
			ans = __gcd(ans, i);
			ans = __gcd(ans, n / i);
		}
	}
	if(ans == 0)
	{
		cout << n;
	}
	else
	cout << ans;
}