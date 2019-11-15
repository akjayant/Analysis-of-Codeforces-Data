#include <bits/stdc++.h>
using namespace std;

string to_string(bool x) {
    return x ? "true" : "false";
}

string to_string(char x) {
    return string(1, x);
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() {
    cerr << endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define fi first
#define se second
#define two(a) (1LL << (a))
#define has(mask, i) ((mask >> i) & 1)

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector < int >;
using vll = vector < ll >;
using vvi = vector < vector < int > >;
using vpii = vector < pii >;
using ld = long double;
using vs = vector < string >;

mt19937_64 rnd((unsigned long) chrono::high_resolution_clock::now().time_since_epoch().count());

void solve() {
    int t; cin >> t;
    while(t--) {
        int n, r, p, s;
        cin >> n >> r >> p >> s;
        string t; cin >> t;
        int res = 0;
        vector < int > was(n, 0);
        vector < char > ans(n);




        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'R' && p > 0) {
                res++;
                p--;
                ans[i] = 'P';
                was[i] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'S' && r > 0) {
                res++;
                r--;
                was[i] = 1;
                ans[i] = 'R';
            }
        }
        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'P' && s > 0) {
                res++;
                was[i] = 1;
                s--;
                ans[i] = 'S';
            }
        }






        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'P' && p > 0) {
                was[i] = 1;
                p--;
                ans[i] = 'P';
            }
        }
        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'R' && r > 0) {
                was[i] = 1;
                r--;
                ans[i] = 'R';
            }
        }
        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'S' && s > 0) {
                s--;
                ans[i] = 'S';
                was[i] = 1;

            }
        }








        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'S' && p > 0) {
                p--;
                ans[i] = 'P';
                was[i] = 1;

            }
        }
        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'P' && r > 0) {
                r--;
                ans[i] = 'R';
                was[i] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(was[i]) continue;
            if(t[i] == 'R' && s > 0) {
                s--;
                ans[i] = 'S';
                was[i] = 1;
            }
        }

        assert(s + r + p == 0);

        if(res * 2 >= n) {
            cout << "YES\n";
            for(auto x : ans) cout << x;
            cout << endl;
        }
        else {
            cout << "NO\n";
        }


    }   
}

int main() {
#ifdef LOCAL
    freopen("xxx.in", "r", stdin);
    freopen("xxx.out", "w", stdout);
    auto start_time = clock();
#else
    // ???
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(12);
    cerr.setf(ios::fixed | ios::showpoint);
    cerr.precision(4);

    solve();

#ifdef LOCAL
    auto end_time = clock();
    cerr << "time: " << (end_time - start_time) * 1.0 / CLOCKS_PER_SEC << endl;
#endif

    return 0;
}