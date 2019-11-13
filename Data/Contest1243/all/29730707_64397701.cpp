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
int cnt[50];
vector <pair <int, int> > vec;
main()
{
	int q, n;
	cin >> q;
	forn(1, te, q)
	{
		memset(cnt, 0, sizeof cnt);
		cin >> n;
		cin >> s >> t;
		FOR(0, i, s.size())
		{
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']++;
		}
		int no = 0;
		FOR(0, i, 'z' - 'a')
		{
			if(cnt[i] % 2 == 1)
			{
				no = 1;
				cout << "No\n";
				break;
			}
		}
		if(no) continue;
		FOR(0, i, s.size())
		{
			if(s[i] != t[i])
			{
				FOR(i + 1, j, s.size())
				{
					if(t[i] == t[j] && s[i] == s[j])
					{
						swap(t[i], s[j]);
						vec.pb(mp(j, i));
						break;
					}
				}
				if(t[i] == s[i]) continue;
				FOR(i + 1, j, s.size())
				{
					if(s[j] == s[i])
					{
						swap(t[i], s[j]);
						vec.pb(mp(j, i));
						break;
					}
				}
				if(t[i] == s[i]) continue;
				FOR(i + 1, j, t.size())
				{
					if(t[j] == s[i])
					{
						swap(s[j], t[j]);
						vec.pb(mp(j, j));
						swap(s[j], t[i]);
						vec.pb(mp(j, i));
						break;
					}
				}
			}
		}
		cout << "Yes\n" << vec.size() << endl;
		FOR(0, i, vec.size())
		{
			cout << vec[i].f + 1 << " " << vec[i].s + 1 << endl;
		}
		vec.clear();
	}
}