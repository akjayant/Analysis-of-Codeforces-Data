#include <bits/stdc++.h>

using namespace std;

//region debugging

#ifdef LOCAL
#include "debugging.h"
#else
#define to_string(...) 0
#define debug_out(...) 0
#define debug(...) 0
#endif

//endregion debugging

//region typedef abbreviations

using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvpii = vector<vector<pair<int, int>>>;
using ll = long long;
using pll = pair<long long, long long>;
using vl = vector<long long>;
using vpll = vector<pair<long long, long long>>;
using vvl = vector<vector<long long>>;
using vvpll = vector<vector<pair<long long, long long>>>;

//endregion typedef abbreviations

// region rep, trav, all, sz

#define REP(i, a, b) for(remove_reference<decltype((b))>::type i = (a); i < (b); ++i)
#define TRAV(a, x) for(auto& a : (x))
#define ALL(x) begin(x), end(x)
#define rep(i, a, b) for(remove_reference<decltype((b))>::type i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : (x))
#define all(x) begin(x), end(x)


template<typename T>
int sz(T x) {
    return (int) x.size();
}

// endregion rep, trav, all, sz

constexpr ll MOD = 1'000'000'000ll + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.exceptions(cin.failbit);


#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int q;
    cin >> q;
    while (q--) {
    int n; cin >> n;
    vi a(n);
    trav(x, a) {
        cin >> x;
    }
    sort(all(a));
    int mx = -1;
    for (int i=n-1; i>=0; --i) {
        mx = max(mx, min(n-i,a[i]));
    }
    cout << mx << endl;

    }


    return 0;
}
