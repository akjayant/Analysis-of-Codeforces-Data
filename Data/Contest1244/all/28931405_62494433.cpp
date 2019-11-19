#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    if (a[0] == a[n - 1]) {
        cout << 0 << endl;
        return 0;
    }
    ll l = 0, r = n - 1;
    while (l < n - 1 && a[l + 1] == a[l]) {
        l++;
    }
    while (r > 0 && a[r - 1] == a[r]) {
        --r;
    }
    ll lb = a[0], rb = a[n - 1];
    ++l;
    --r;
    while (l < n - 1 && a[l + 1] == a[l]) {
        l++;
    }
    while (r > 0 && a[r - 1] == a[r]) {
        --r;
    }
    while (lb < rb) {
        ll cl = lower_bound(all(a), a[l]) - a.begin();
        ll cr = upper_bound(all(a), a[r]) - a.begin();
        cr = n - cr;
        //    cout << lb << " " << rb << " " << cl << " " << cr << " " << k <<
        //    endl;
        if (cl < cr) {
            if (k >= cl * (a[l] - lb)) {
                k -= cl * (a[l] - lb);
                lb = a[l];
            } else {
                cout << rb - (lb + k / cl) << endl;
                return 0;
            }
            ++l;
            while (l < n - 1 && a[l + 1] == a[l]) {
                l++;
            }
        } else {
            if (k >= cr * (rb - a[r])) {
                k -= cr * (rb - a[r]);
                rb = a[r];
            } else {
                cout << (rb - k / cr) - lb << endl;
                return 0;
            }
            --r;
            while (r > 0 && a[r - 1] == a[r]) {
                --r;
            }
        }
    }
    cout << 0 << endl;
}