/** Simplicity is the final achievement **/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+55;
const long long MD = 1e9+7;

long long t, n, m;

long long arr[N];

int32_t main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/

    cin >> n;
    if (n == 1) return cout << 1, 0;

    long long i, p[10], ind = 0, ncp = n, g = n;

    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) g = __gcd(__gcd(i, n/i), g);
    }
    return cout << g, 0;

    if (g == 1) return cout << 1, 0;
    if (g == n) return cout << n, 0;

    return 0;
}
