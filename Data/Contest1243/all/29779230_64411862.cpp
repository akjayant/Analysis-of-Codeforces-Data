#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int k;
    cin >> k;
    forn (i, k) {
        ll n;
        vector <deque <int>> sp(26);
        vector <deque <int>> tp(26);
        vpi ans;
        cin >> n;
        string s, t;
        cin >> s >> t;
        forn (j, n) {
            sp[s[j] - 'a'].pb(j);
            tp[t[j] - 'a'].pb(j);
        }

        bool ok = true;

        forn (j, n) {
            if (s[j] == t[j]) {
                continue;
            }
            bool find = false;
            ll z = -1;
            for (int l = j + 1; l < n; ++l) {
                if (t[l] == t[j]) {
                    z = l;
                    break;
                }
            }
            if (z != -1) {
                ans.pb({ j + 1, z + 1});
                swap(s[j], t[z]);
                continue;
            }

            for (int l = j + 1; l < n; ++l) {
                if (s[l] == t[j]) {
                    z = l;
                    break;
                }
            }
            if (z != -1) {
                swap(s[z], t[n-1]);
                swap(s[j], t[n-1]);
                ans.pb({ z + 1, n});
                ans.pb({ j + 1, n});
                continue;
            }
            else {
                cout << "No\n";
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes\n";
            cout << ans.size() << "\n";
            for (auto j : ans) {
                cout << j.first << " " << j.second << "\n";
            }
        }
    }
}