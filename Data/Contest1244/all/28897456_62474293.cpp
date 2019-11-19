//#pragma GCC target ("avx2,sse2")
//#pragma GCC optimization ("Ofast")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define endl "\n"
#define int long long
using namespace std;

void dout() {
    cerr << endl;
}

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(int tc) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int last = -1, res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            res1++;
            last = i;
        }
        res1++;
    }
    if (last != -1) {
        res2 = (last + 1) * 2;
    }
    int ans = max(res1, res2);

    last = -1, res1 = 0, res2 = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            res1++;
            last = i;
        }
        res1++;
    }
    if (last != -1) {
        res2 = (last + 1) * 2;
    }
    cout << max(ans, max(res1, res2)) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}
