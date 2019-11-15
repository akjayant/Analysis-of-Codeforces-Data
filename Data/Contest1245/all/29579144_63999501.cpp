#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define sz(x) (int)x.size()
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a,b ,c;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    vector<char> ans(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        auto cc = s[i];
        //cout << c << endl;
        if (cc == 'R' && b) {
            ans[i] = 'P';
            --b;
            ++cnt;
        }
        if (cc == 'P' && c) {
            ans[i] = 'S';
            --c;
            ++cnt;
        }
        if (cc == 'S' && a) {
            ans[i] = 'R';
            --a;
            ++cnt;
        }
       // cout << cnt <<" " << a << " " << b << " " << c << endl;
    }
   // cout << "cnt " << cnt << endl;
    if (cnt * 2 < n) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (char i : ans) {
        if (i)
            cout << i;
        else if (a) {
            --a;
            cout << "R";
        } else if (b) {
            --b;
            cout << "P";
        } else {
            --c;
            cout << "S";
        }
    }
    cout << "\n";
}

signed main() {
    using namespace std;
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
