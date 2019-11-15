#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
 
#define FOR(i, x, n) for(ll i = x; i < n; i++) 
#define pb push_back
#define pf push_front
#define ll long long
#define hii cout << "hii" << endl
#define pii pair<int, int>
#define pll pair<ll, ll>
#define int ll
#define mpp make_pair
#define endl '\n'
#define ff first 
#define ss second
#define vi vector<int>
#define all(s) s.begin(), s.end()
#define si size()
 
template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << v.first << ' ' << v.second; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; } 
 
 
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <class Arg1> void __f(const char* name, Arg1&& arg1) { cerr << name << " : " << arg1 << endl; }
    template <class Arg1, class... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args) {
        const char* sep = strchr(names + 1, ',');
        cerr.write(names, sep - names) << " : " << arg1 << "  ";
        __f(sep + 1, args...);
    }
#else
#define trace(...) 0
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#endif // ifndef ONLINE_JUDGE
 
 
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
 
int n;
int arr[N];
 
void solve()
{
	int a, b, c;
	cin >> a >> b >> c;
	int ret = 0;
	while(c > 1 and b > 0)
	{
		ret += 3;
		b--;
		c -= 2;
	}

	while(a > 0 and b > 1)
	{
		ret += 3;
		a--;
		b -= 2;
	}
	cout << ret << endl;
}
 
 
 
int32_t main()
{	
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	int t = 1;
	cin >> t;
	while(t--)solve();
	return 0;
}
 