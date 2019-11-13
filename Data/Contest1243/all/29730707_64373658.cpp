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
const ll maxn=1e6+100,inf=1e18,LOG=20,mod=1e9 + 3;
#define int ll

int n, ans, a[maxn];

main()
{
	int q;
	cin >> q;
	forn(1, te, q)
	{
		ans = 0;
		cin >> n;
		forn(1, i, n)
		{
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		forn(1, i, n)
		{
			if(n - i + 1 >= a[i])
			{
				ans = max(ans, a[i]);
			}
			else
			{
				ans = max(ans, n - i + 1);
			}
		}
		cout << ans << endl;
	}
}