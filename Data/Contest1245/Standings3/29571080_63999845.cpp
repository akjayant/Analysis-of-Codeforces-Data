#include <bits/stdc++.h>

#define need_long 0

#define all(v) v.begin(), v.end()
#define vc vector
#define len(v) ((int) v.size())
#define pr pair
#define ld long double
#define mset multiset

using namespace std;

#if need_long == 1
#define int long long
#else
#endif
const int INF = (need_long) ? 1e18 : 2e9;
mt19937 gen(time(0));

template <class T> int upmax(T &a, T b) {
    return (b > a) ? a = b, 1 : 0;
}

template <class T> int upmin(T &a, T b) {
    return (b < a) ? a = b, 1 : 0;
}

template <class T> void output(vc<T>&a, ostream &out = cerr, string r = " ") {
    for (int i = 0; i < len(a); ++i) {
        cout << a[i] << r;
    }
    out << "\n";
}

const int MAXN = 3e5 + 40;
const int LOG = 30;

void solve() {
    map <pr<int, int>, int> mp;
    mp[{'R', 'S'}]++;
    mp[{'S', 'P'}]++;
    mp[{'P', 'R'}]++;

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    vector <int> rock, paper, sc;
    string res;
    res.resize(n, '?');
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'R') rock.push_back(i);
        if (s[i] == 'P') paper.push_back(i);
        if (s[i] == 'S') sc.push_back(i);
    }
    while (a > 0 && len(sc)) {
        res[sc.back()] = 'R';
        sc.pop_back();
        a--;
    }
    while (b > 0 && len(rock)) {
        res[rock.back()] = 'P';
        rock.pop_back();
        b--;
    }
    while (c > 0 && len(paper)) {
        res[paper.back()] = 'S';
        paper.pop_back();
        c--;
    }
    for (int i = 0; i < n; ++i) {
        if (res[i] != '?') continue;
        if (a > 0) {
            res[i] = 'R';
            a--;
            continue;
        }
        if (b > 0) {
            res[i] = 'P';
            b--;
            continue;
        }
        res[i] = 'S';
        c--;
    }
    int win = 0;
    for (int i = 0; i < n; ++i) {
       if (mp[{res[i], s[i]}]) win++;
    }
    if (win >= (n + 1) / 2) {
        cout << "YES\n";
        cout << res << "\n";
    }
    else {
        cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}