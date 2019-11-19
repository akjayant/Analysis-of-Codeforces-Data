/*

 ∧＿∧
( ･ω･｡)つ━☆・*。
⊂　 ノ 　　　・゜
しーＪ　　 Accepted

*/



// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define all(x) begin(x), end(x)
#define x first
#define y second
#define int long long

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
template<typename T>
using kawaii_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ld PI = atan2(0, -1);

void seriy() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(14);
    #ifdef _offline
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

const int MAXN = 1e5 + 10;
const int MAXM = 600;
const int INF = 1e18;
const int BASE = 47;
const int MOD = 1e9 + 7;
const int MAXLOG = 21;

signed main() {
    seriy();
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int c1 = a / c + (a % c > 0);
        int c2 = b / d + (b % d > 0);
        if(c1 + c2 > k) {
            cout << "-1\n", 0;
        }
        else {
            cout << c1 << " " << c2 << '\n';
        }
    }
    return 0;
}