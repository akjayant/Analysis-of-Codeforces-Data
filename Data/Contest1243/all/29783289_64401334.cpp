#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("mmx,avx,fma")
//#pragma GCC optimize ("unroll-loops")
#define int long long
#define pii pair<int,int>
#define X first
#define Y second
#define ll long long
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define re return
#define pb push_back
#define PI acos(-1)
#define sz(x) ((int)(x).size())
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<double>
#define vc vector<char>
#define vii vector<pii>
#define sq(x) (x)*(x)
#define vsi vector<set<int>>
#define si set<int>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define double long double
#define se second 
#define fi first

#define graph(g,n) vector<set<int>>(g)(n);
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define fore(i,ii,iii) for(int i=ii;i<iii;i++)
#define idata(a, n) int n; cin>>n ; vi a(n); for (int i = 0;i < n;i++)cin >> a[i]
#define read(a,n) for (int i = 0;i < n;i++)cin >> a[i]
#define ivec(a,n)  vi a(n); for (int i = 0;i < n;i++)cin >> a[i]
#define outvec(a,n)  {for (int i = 0;i < n;i++)cout<<a[i]<<" "; cout<<'\n';}
#define make_unique(a) sort(all(a)); a.resize(unique (all(a))-a.begin())
#define _ans(x) {cout<<(x)<<'\n'; re 0;}
#define INF (int)(1e9)
#define EPS (1e-6)
#define mod (int)(1e9+123) //1e9+123, 1e9+321, 1500000001

using namespace std;

int dj[] = { 1,0,-1,0 };
int di[] = { 0,1,0,-1 };

//int di[] = { -2,-1,1,2,2,1,-1,-2 };
//int dj[] = { 1,2,2,1,-1,-2,-2,-1 };

int fine(int i, int j, int n, int m) {
	re i >= 0 && i < n && j >= 0 && j < m;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	/*int n;
	cin >> n;
	queue<int>q;
	vector<int>used(n + 1, 0);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cnt++;
			q.push(i);
			used[i] = cnt;
			while (q.size()) {
				int i = q.front();
				q.pop();
				for (int j = 1; j <= n; j++) {
					if (i!=j && abs(i-j)>=2 && n%abs(j - i) == 0) {
						if (!used[j]) {
							used[j] = cnt;
							q.push(j);
						}
					}
				}
			}
		}
	}*/
	int n;
	cin >> n;
	map<int, int>fact;
	int t = n;
	if (n == 1)_ans(1);
	for (int i = 2; i*i <= t; i++) {
		while (t%i == 0) {
			fact[i]++;
			t /= i;
		}
	}
	if (t > 1)fact[t]++;
	if (fact.size() > 1)_ans(1);
	t = fact.begin()->first;
	if (fact[t] == 1)cout << n;
	else cout <<t<< '\n';
	//cout << cnt;
}
