//                             In The Name Of Allah
#include <bits/stdc++.h>
#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) return cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#define int long long
using namespace std; 
 
const int N = 1e6 + 100, OO = 1e18, M = 1e9 + 7, P = 6151, sq = 360, lg = 23;
typedef pair <int, int> pii;

int32_t main() {
    use_fast;
    int t;
    cin >> t;
    while(t--) {
    	int a, b, c, d, k;
    	cin >> a >> b >> c >> d >> k;
    	a = (a + c - 1) / c;
    	b = (b + d - 1) / d;
    	if(a + b > k)
    		cout << -1 << endl;
    	else
    		cout << a << " " << b << endl;
	}
	return 0;
} 
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/
