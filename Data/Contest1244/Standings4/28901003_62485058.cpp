#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 100005;
const ll mod = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k, a[N], mn, mx, l, r;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
        cin >> a[i];
	}
	l = 1, r = n;
	sort (a+1, a+1+n);
	mn = a[1], mx = a[n];
	for (int q=1; q<n; q++) {
        ll c1, c2;
        c1 = (a[l+1]-a[l])*l;
        c2 = (a[r]-a[r-1])*(n-r+1);
        if (l <= (n-r+1)) {
            if (k < c1) break;
            k -= c1;
            l ++;
            mn = a[l];
        } else {
            if (k < c2) break;
            k -= c2;
            r --;
            mx = a[r];
        }
	}
	if (l <= (n-r+1)) mn += k/l;
    else mx -= k/(n-r+1);
	cout << max(mx-mn, 0ll);
    return 0;
}
