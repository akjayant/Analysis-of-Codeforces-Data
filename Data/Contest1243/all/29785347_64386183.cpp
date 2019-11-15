#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e5 + 5;
const ll INF = 1e9 + 7;

ll n, T, a[N], RMQ[N][19];

int main() {
    //freopen("1243A.INP", "r", stdin);
    //freopen("1243A.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (ll i = 1; i <= n; i++) cin >> a[i];
        //********************
        sort(a + 1, a + n + 1);
        ll kq = 0;
        for (ll i = 1; i <= n; i++)
            kq = max(kq, min(a[i], n - i + 1));
        //********************
        cout << kq << endl;
    }
    return 0;
}
