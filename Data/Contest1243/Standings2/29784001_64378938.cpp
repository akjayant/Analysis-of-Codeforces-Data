#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define lb lower_bound
#define ub upper_bound
#define Loop(i, a, b) for(int i = a ; i < b ; ++i)
#define loop(i, n) Loop(i, 0, n)
#define ff first
#define ss second
#define mkp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vl vector<ll>
#define vvl vector<vl>
#define pll pair<ll, ll>
#define vll vector<pll>
#define vvll vector<vll>
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define nmbr(c) (int)(c-'0')
#define ltr(c) (int)(c-'a')
#define INF 1e18+5
#define inf 1e9+5
#define _69e27 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define trace(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

template <typename T> T max(T a, T b, T c){ return max(a, max(b, c));}
template <typename T> T min(T a, T b, T c){ return min(a, min(b, c));}

int M = 1e9+7; //check


int main() {
	_69e27;
	int T;
	cin >> T;

	while(T--)
	{
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		if(s == t)
		{
			cout << "YES\n";
			continue;
		}
		vi p;
		loop(i, n)
		{
			if(s[i] != t[i]) p.pb(i);
		}
		if(sz(p) != 2)
		{
			cout << "NO\n";
			continue;
		}
		if(s[p[0]] == s[p[1]] && t[p[0]] == t[p[1]]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}