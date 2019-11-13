#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define INF 2000000000000000000;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll k;
    cin >> k;

    while (k--) {
        ll n;
        cin >> n;

        string s;
        cin >> s;

        string t;
        cin >> t;

        vector<ll> diffs;

        for (ll i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                diffs.push_back(i);
            }
        }
        if (diffs.empty()) {
            cout << "Yes" << endl;
            continue;
        }

        if (diffs.size() == 2 && s[diffs[0]] == s[diffs[1]] && t[diffs[0]] == t[diffs[1]] ) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}