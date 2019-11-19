#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

#define ff first
#define ss second

const double eps = 1e-6;
const int mod = 45;
const int maxn = 1e5 + 7;

int main() {
#ifdef JOPA
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll x = 0, y = 0;
    for (int i = 0; i < n / 2; i++) {
        x += a[i];
    }
    for (int i = n / 2; i < n; i++) {
        y += a[i];
    }

    cout << x * x + y * y;


    return 0;
}
