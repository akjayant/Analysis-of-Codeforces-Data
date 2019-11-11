//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")
           
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
           
using namespace std;
using namespace __gnu_pbds;
           
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
           
using matrix = vector<vector<ll>>;
template<typename T>
using kawaii_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
           
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
//#define int long long;
           
void FAST_IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(20);
    #ifndef _offline
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
}

signed main() {
    FAST_IO();
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s, res = string(n, 'a');
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                if (b > 0) {
                    res[i] = 'P';
                    b--;
                    cnt++;
                }
            }
            else if (s[i] == 'P') {
                if (c > 0) {
                    res[i] = 'S';
                    c--;
                    cnt++;
                }
            }
            else {
                if (a > 0) {
                    res[i] = 'R';
                    a--;
                    cnt++;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (res[i] == 'a') {
                if (a > 0) {
                    res[i] = 'R';
                    a--;
                }
                else if (b > 0) {
                    res[i] = 'P';
                    b--;
                }
                else {
                    res[i] = 'S';
                    c--;
                }
            }
        }
        if (cnt >= ((n + 1) / 2)) {
            cout << "YES\n";
            cout << res << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
} 
