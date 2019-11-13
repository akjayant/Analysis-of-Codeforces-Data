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
        string s, t;
        cin >> s >> t;

        vi different;
        map<char, int> schars, tchars;
        for (int i=0; i<n; ++i) {
            ++schars[s[i]];
            ++tchars[t[i]];
            if (s[i]!=t[i]) different.push_back(i);
        }
        bool yes = false;
        if (sz(different)==2) {
            char s1, s2, t1, t2;
            s1 = s[different[0]];
            s2 = s[different[1]];
            t1 = t[different[0]];
            t2 = t[different[1]];
            if (t1==t2 && s1==s2) {
                yes = true;
            }

        }
        if (yes) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }


    return 0;
}
