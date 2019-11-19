#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define endl '\n'
#define TIME 1.0*clock()/CLOCKS_PER_SEC

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e6 + 7;
const int M = 1e9 + 7;
const int FFTM = 998244353;

ll n, k;
vector<int> a, b;

int f(int i, int j){
    return  - max(a[j], b[j]) - max(a[i], b[i]) + max(a[j], b[i]) + max(a[i], b[j]);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> k;
    ll res = 0;
    for (int i = 1; i <= n; i++) a.pb(i);
    for (int i = 1; i <= n; i++) b.pb(i), res += i;
    if (res > k){
        cout << -1;
        return 0;
    }
    int j = 0;
    for (int i = n - 1; i >= 0; i--){
        while (j < i && res + f(i, j) > k) j++;
        if (j < i) res += f(i, j), swap(b[i], b[j]);
        j++;
    }
    cout << res << endl;
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    return 0;
}