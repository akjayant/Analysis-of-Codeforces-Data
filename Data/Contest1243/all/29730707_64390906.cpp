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
string s, t;
vector <int> vec;
main()
{
	int q, n;
	cin >> q;
	forn(1, te, q)
	{
		int ans = 0;
		vec.clear();
		cin >> n;
		cin >> s >> t;
		if(s == t)
		{
			cout << "Yes\n";
			continue;
		}
		FOR(0, i, s.size())
		{
			if(t[i] != s[i])
			{
				ans++;
				vec.pb(i);
			}
		}
		if(ans == 2 && t[vec[0]] == t[vec[1]] && s[vec[1]] == s[vec[0]])
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
	}
}