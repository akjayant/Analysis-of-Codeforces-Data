#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;

// @fs4k 1243 B2

// active types
typedef int32_t          i32;
typedef pair<i32,i32>    p32;
typedef vector<i32>      v32;
typedef vector<p32>   	vp32;
typedef int64_t          i64;
typedef pair<i64,i64>    p64;
typedef vector<i64>      v64;
typedef vector<p64>     vp64;
typedef float            f32;
typedef pair<f32,f32>   pf32;
typedef vector<f32>     vf32;
typedef vector<pf32>   vpf32;
typedef double           f64;
typedef pair<f64,f64>   pf64;
typedef vector<f64>     vf64;
typedef vector<pf64>   vpf64;

// active definitions
#define mp make_pair
#define pb push_back
#define beg begin
#define fi first
#define se second
#define debug(x) cerr << "DEBUG::" #x ":\t" << x << endl
#define loop(i,a,b) for(auto i = (a); i != (b); i++)
#define loopf(i,a,b) for(auto i = (a); i < (b); i++)
#define loopb(i,a,b) for(auto i = (a); i > (b); i--)
#define tee() i32 T; cin >> T; while(T--)
#define prime 1e9+7

// I/O operator overloads
template<typename P, typename Q>
istream &operator>>(istream &is, pair<P,Q> &p) {
    return is >> p.fi >> p.se;
}

template<typename P>
istream &operator>>(istream &is, vector<P> &v) {
    loop(i,0,v.size()) is >> v[i];
    return is;
}

template<typename P, typename Q>
ostream &operator<<(ostream &os, pair<P,Q> &p) {
    return os << p.fi << ' ' << p.se;
}

template<typename P>
ostream &operator<<(ostream &os, vector<P> &v) {
    if (0 < v.size()) {
        os << v[0];
        loop(i,1,v.size()) os << ' ' << v[i];
    }
    return os;
}

i32 main() {
    tee() {
        i32 n; string s, t;
        cin >> n >> s >> t;
        v32 f(26, 0);
        loop(i,0,n) {
            f[s[i] - 'a']++;
            f[t[i] - 'a']++;
        }
        bool output = true;
        loop(i,0,26) {
            if (f[i] & 1) {
                output = false;
                break;
            }
        }
        if (output) {
            cout << "Yes" << endl;
            multiset<pair<char,i32>> S, T;
            loop(i,0,n) {
                S.insert(mp(s[i], i));
                T.insert(mp(t[i], i));
            }
            vp32 swaps;
            loop(i,0,n) {
                S.erase(mp(s[i], i));
                T.erase(mp(t[i], i));
                // debug(s[i]); debug(t[i]);
                if (s[i] != t[i]) {
                    auto iter = T.lower_bound(mp(t[i], 0));
                    if (iter != T.end() && iter->first == t[i]) {
                        i32 j = iter->se;
                        // swap s[i] and t[j];
                        T.erase(mp(t[j], j));
                        swap(s[i], t[j]);
                        T.insert(mp(t[j], j));
                        swaps.pb(mp(i+1, j+1));
                        // debug(swaps);
                        continue;
                    }
                    iter = S.lower_bound(mp(t[i], 0));
                    if (iter != S.end() && iter->first == t[i]) {
                        i32 j = iter->se;
                        // debug(j);
                        // swap s[j] and t[j], then swap s[i] and t[j]
                        // swap s[j] and t[j]
                        S.erase(mp(s[j], j));
                        T.erase(mp(t[j], j));
                        swap(s[j], t[j]);
                        S.insert(mp(s[j], j));
                        T.insert(mp(t[j], j));
                        // swap s[i] and t[j]
                        T.erase(mp(t[j], j));
                        swap(s[i], t[j]);
                        T.insert(mp(t[j], j));
                        swaps.pb(mp(j+1, j+1));
                        swaps.pb(mp(i+1, j+1));
                        // debug(swaps);
                    }
                }
            }
            cout << swaps.size() << ' ' << swaps << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
