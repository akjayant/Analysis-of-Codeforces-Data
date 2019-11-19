#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


template <class T> ostream& operator << (ostream &os, const vector<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T> ostream& operator << (ostream &os, const set<T> &v) { for (T i : v) os << i << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const pair<T, S> &v) { os << '(' << v.first << ' ' << v.second << ')'; return os; }
template <class T, class S> ostream& operator << (ostream &os, const map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
template <class T, class S> ostream& operator << (ostream &os, const unordered_map<T, S> &v) { for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' '; return os; }
#define endl "\n"
#define max_heap priority_queue<int>
#define min_heap priority_queue<int , vector<int>, greater<int> >
#define pb push_back
#define print(name,from,to) {for(int x = from; x < to; x++) cout << name[x] << " "; cout << endl;}
#define ff first
#define ss second
#define int ll
 
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


const ll MOD = 1000000007;
const ll INF = 1e18;
const double EPS = 1e-5;

void solve()
{
	int n, m, x;
	cin >> n;
	int o1 = 0, e1 = 0, o2 = 0, e2 = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		o1 += (x%2);
		e1 += 1-(x%2);
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> x;
		o2 += (x%2);
		e2 += 1-(x%2);
	}
	cout << o1*o2 + e1*e2 << endl;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	clock_t t1, t2;
	
	int T = 1;
	cin >>  T;
	while (T--) {
		solve();
	}

	t1 = clock();
	t2 = clock(); cerr << "time taken: " << (t2-t1)/(long double)CLOCKS_PER_SEC << endl;
	return 0;
}
