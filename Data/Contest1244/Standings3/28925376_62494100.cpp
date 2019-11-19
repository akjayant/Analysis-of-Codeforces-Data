#include<bits/stdc++.h>
using namespace std;

#define ll long long

inline ll read() {
    ll x = 0, f = 1; char ch = getchar();
    for(; ch < '0' || ch>'9'; ch = getchar())
        if(ch == '-') f = -f;
    for(; ch >= '0' && ch <= '9'; ch = getchar())
        x = x * 10 + ch - '0';
    return x * f;
}

inline void chkmin( int &a, int b ) { if(a > b) a = b; }

inline void chkmax( int &a, int b ) { if(a < b) a = b; }

#define _ read()

#define ln endl

const int N = 2e5 + 5;

int n;
ll k, a[N];

int main()
{
	n = _; k = _;
	for( int i = 1; i <= n; i++ ) 
		a[i] = _;
	sort( a + 1, a + n + 1);
	ll mx = a[n], mn = a[1];
	// cout << upper_bound(a + 1, a + n + 1, 1) - a << ln;
	while(k >= 0) 
	{
		if(mn >= mx) return puts("0") ,0;
		int pos1 = upper_bound(a + 1, a + n + 1, mn) - a;
		int pos2 = lower_bound(a + 1, a + n + 1, mx) - a;
		--pos1;
		// cout << pos1 << " " << pos2 << " ";
		if(n - pos2 + 1 <= pos1)
		{
			// puts("r");
			ll tmp = k / ( n - pos2 + 1);
			if(tmp == 0) break;
			k -= min(mx - a[pos2 - 1], tmp) * ( n - pos2 + 1);
			mx -= min(mx -a[pos2 - 1], tmp);
		} else
		{
			// puts("l");
			ll tmp = k / pos1;
			if(tmp == 0) break;
			// cout << tmp << ln;
			k -= min(a[pos1 + 1] - mn, tmp) * pos1;
			mn += min(a[pos1 + 1] - mn, tmp);
		}
		// cout << k << ln;
		// cout << mn << " " << mx << ln;
	}
	cout << max(mx - mn, 0ll) << ln;
}