#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define re(n) for (int i = 0; i < (n); ++i)
#define rej(n) for (int j = 0; j < (n); ++j)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <pair <int, int>> vii;
typedef vector <vector <int>> vvi;

const ld PI = acos((ld)-1);

vii ans;

void ss(char &x, char &y, int i, int j) {
    swap(x, y);
    ans.emplace_back(i + 1, j + 1);
}

bool go(string s, string t, int n) {
    re(n) {
        if (s[i] == t[i]) {
            
        } else {
            bool f = false;
            for (int j = i + 1; j < n; ++j) {
                if (t[j] == t[i]) {
                    ss(s[i], t[j], i, j);
                    f = true;
                    break;
                }
            }
            if (!f) {
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == s[i]) {
                        ss(t[i], s[j], j, i);
                        f = true;
                        break;
                    }
                }
            }
            if (!f) {
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == t[i]) {
                        ss(t[n - 1], s[j], j, n-1);
                        ss(t[n - 1], s[i], i, n-1);
                        f = true;
                        break;
                    }
                }
            }
            if (!f) {
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == t[i]) {
                        ss(s[n - 1], t[j], n-1, j);
                        ss(s[n - 1], t[i], n-1, i);
                        f = true;
                        break;
                    }
                }
            }
            if (!f || s[i] != t[i]) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int a[26] = {0};
    deque <int> v[26], u[26];
    re(n) {
        ++a[s[i] - 'a'];
    }
    re(n) {
        ++a[t[i] - 'a'];
    }
    re(26) if (a[i] % 2 == 1) {
        cout << "No\n";
        return;
    }
    ans.clear();
    bool fu = go(s, t, n);
    if (!fu || ans.size() > 2 * n) {
        ans.clear();
        fu = go(t, s, n);
    }
    if (fu) {
        cout << "Yes\n";
        cout << sz(ans) << '\n';
        re(sz(ans)) {
            cout << ans[i].fi << ' ' << ans[i].se << '\n';
        }
    } else {
        cout << "No\n";
    }
}

int main() {
    #ifndef LOCALDEBUG
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #endif  // LOCALDEBUG
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
