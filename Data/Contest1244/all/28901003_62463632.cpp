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
	ll q;
	cin >> q;
	while (q) {
        q --;
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if (a/c+bool(a%c)+b/d+bool(b%d) <= k) {
            cout << a/c+bool(a%c) << " " << b/d+bool(b%d) << E;
        } else cout << -1 << E;
	}
    return 0;
}
