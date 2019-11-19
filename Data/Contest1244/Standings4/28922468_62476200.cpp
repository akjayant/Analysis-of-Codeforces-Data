#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

typedef long long ll;
#define READ(a) int a; cin >> a;
#define READARR(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define READMAT(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const ll inf = 1e18;
const ll mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	int mn = (p - d*n)/(w - d);
	if ((p - d*n) % (w - d)) mn++;
	mn = max(0LL, mn);
	
	int st = 0;
	FOR (i, mn, mn + d + 5)
	{
	    if ((p - i*w) >= 0 && (p - i*w) % d == 0) 
	    {
	        cout << i << " " << (p - i*w)/d << " " << n - (i + (p - i*w)/d);
	        st = 1;
	        break;
	    }
	}
	
	if (!st) cout << -1;
}