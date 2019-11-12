#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, x) for(int i = 0; i < x; i++)
#define rforn(i, x) for(int i = x - 1; i >= 0; i--)

using namespace std;

template<typename T> void print(T a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> a(26, 0), b(26, 0);

    forn (i, n) 
        a[s[i] - 'a']++;
    forn (i, n) 
        b[t[i] - 'a']++;

    bool ok = true;
    forn (i, 26) {
        if ((a[i] + b[i]) & 1)
            ok = false;
    }

    int cnt1 = 0, cnt2 = 0;
    forn (i, 26) {
        if (a[i] > b[i]) 
            cnt1 += a[i] - b[i];
        else
            cnt2 += b[i] - a[i];
    }  

    if (cnt1 != cnt2)
        ok = false;

    if (!ok) {
        cout << "NO" << '\n';
        return;
    }

    vector<pii> ans;
    forn (i, n) {
        if (s[i] == t[i])
            continue;

        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                ans.pb({j, i});
                swap(s[j], t[i]);
                break;
            }
            if (s[i] == t[j]) {
                ans.pb({j, j});
                swap(s[j], t[j]);
                ans.pb({j, i});
                swap(s[j], t[i]);
                break;
            }
        }
    }

    if (s != t) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    cout << sz(ans) << '\n';
    forn (i, sz(ans)) 
        cout << ++ans[i].ff << ' ' << ++ans[i].ss << '\n';
}

signed main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    forn (i, k)
        solve();    

    return 0;
}
