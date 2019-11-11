#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

typedef long long ll;
#define READ(a) int a; cin >> a;
#define READARR(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define READMAT(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define print(a, n) FOR (i, 1, n) cout << a[i] << " "; cout << endl;
#define printmat(a, n, m) FOR (i, 1, n) {FOR (j, 1, m) cout << a[i][j] << " "; cout << endl;} cout << endl;
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
	
	READ(t);
	while (t--)
	{
	    int n, r, p, s;
	    string str;
	    cin >> n >> r >> p >> s >> str;
	    
	    int cnt = 0, rr = r, pp = p, ss = s;
	    string ans;
	    for (char i: str)
	    {
	        if (i == 'S' && rr) cnt++, rr--, ans.pb('R');
	        else if (i == 'P' && ss) cnt++, ss--, ans.pb('S');
	        else if (i == 'R' && pp) cnt++, pp--, ans.pb('P');
	        else ans.pb('X');
	    }
	    
	    int half = n/2;
	    if (n % 2) half++;
	    if (cnt < half) {cout << "NO" << endl; continue;}
	    
	    FOR (i, 0, n - 1)
    	    if (ans[i] == 'X')
    	    {
    	        if (rr) ans[i] = 'R', rr--;
    	        else if (pp) ans[i] = 'P', pp--;
    	        else ans[i] = 'S', ss--;
    	    }
    	
    	cout << "YES\n" << ans << endl;
	}
}