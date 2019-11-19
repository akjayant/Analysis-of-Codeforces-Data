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

const int MAXN = 1e6 + 10;
const int MAXM = 600;
const int INF = 1e18;
const int BASE = 47;
const int MOD = 1e9 + 7;
const int MAXLOG = 21;

signed main() {
    seriy();
    int n, k;
    cin >> n >> k;
    deque<int> a(n);
    deque<int> b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j < n && a[j] == a[i]) {
            j++;
        }
        j--;
        b.push_back(j - i + 1);
        i = j;
    }
    a.resize(unique(all(a)) - a.begin());
    int l = a[0];
    int rg = a.back();
    while(k && b.size() > 1) {
        int cnt = min(b[0], b.back());
        if(k < cnt) {
            k = 0;
            break;
        }
        if(b[0] <= b.back()) {
            int r = a[1] - a[0];
            if(r * cnt > k) {
                int h = k / cnt;
                l += h;
                break;
            }
            int cur = b[0];
            b.pop_front();
            a.pop_front();
            b[0] += cur;
            l = a[0];
            k -= r * cnt;
        }
        else {
            int r = a[a.size() - 1] - a[a.size() - 2];
            if(r * cnt > k) {
                int h = k / cnt;
                rg -= h;
                break;
            }
            int cur = b.back();
            b.pop_back();
            a.pop_back();
            b[b.size() - 1] += cur;
            rg = a.back();
            k -= r * cnt;
        }
    }
    if(b.size() == 1) {
        cout << 0;
    }
    else {
        cout << rg - l;
    }
    return 0;
}