#include<bits/stdc++.h>
#include<chrono>
#include<random>
#define int long long
#define double long double
#define INF 1e18
#define pii pair<int,int>
#define endl "\n"
#define all(mas) mas.begin(),mas.end()
#define forn(i,n) for(int i = 0; i < n; i++)
#define forn_(i,n) for(int i = n - 1; i >= 0; i--)
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
#ifdef LOCAL_DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif		
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t,n;
	string s;

	cin >> t;

	forn(z, t) {
		cin >> n >> s;
		int fir = -1, lst = -1;

		forn(i, n)
			if (fir == -1 && s[i] == '1')
				fir = i;
		
		forn_(i, n)
			if (lst == -1 && s[i] == '1')
				lst = i;

		int res = n;

		if (fir != -1) res = max(res, 2 * (n - fir));
		if (lst != -1) res = max(res, 2 * (lst + 1));

		cout << res << endl;
	}

	return 0;
}