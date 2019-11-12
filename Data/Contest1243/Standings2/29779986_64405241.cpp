#include <bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;
//#pragma GCC optimize("O3")

const int inf = 1e18;
const int mod = 1e9+7;
const ld eps = 1e-9;
const ld pi = atan2(0, -1);

///---Some Code---///
void solve(string s, string t) {
    map<char, int> m;
    int n = s.size();

    for(int i = 0; i < n; ++i) {
        m[s[i]] += 1;
        m[t[i]] += 1;
    }

    for(auto i : m) {
        if(i.second % 2) {
            cout << "No\n";
            return;
        }
    }

    vector<pair<int, int>> res;
    for(int i = 0; i < n; ++i) {
        if(s[i] == t[i]) continue;

        char c = s[i];
        int pos = -1;
        for(int j = i+1; j < n; ++j)
            if(s[j] == c) pos = j;

        if(pos != -1) {
            res.push_back({pos, i});
            swap(s[pos], t[i]);
        }

        else {
            for(int j = i+1; j < n; ++j)
                if(t[j] == c) pos = j;
            if(pos == -1) {
                cout << "No\n";
                return;
            }

            res.push_back({i, i});
            res.push_back({i, pos});
            swap(t[i], t[pos]);
        }
    }

    cout << "Yes\n" << res.size() << "\n";
    for(auto i : res)
        cout << i.first+1 << " " << i.second+1 << "\n";
}

int32_t main() {
//    freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(15);
//    srand(time(0));
    ///---------///

    int k;
    cin >> k;

    while(k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        solve(s, t);
    }

    ///---------///
    return 0;
}

/**

///---------///

///---------///

///---------///

///---------///

*/
