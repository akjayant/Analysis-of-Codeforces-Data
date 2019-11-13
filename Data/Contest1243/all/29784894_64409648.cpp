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

        vector<ll> a(26);

        for (ll i = 0; i < n; ++i) {
            ++a[s[i] - 'a'];
            ++a[t[i] - 'a'];
        }

        bool ok = true;
        for (ll i = 0; i < 26; ++i) {
            if (a[i] & 1) {
                cout << "No" << endl;
                ok = false;
                break;
            }
        }

        if (!ok) {
            continue;
        }

        cout << "Yes" << endl << 2 * n << endl;
        ll swaps = 0;
        for (ll i = 0; i < n; ++i) {
            if (s[i] == t[i]) {
                cout << "1 1" << endl << "1 1" << endl;
                continue;
            }

            for (ll j = i + 1; j < n; ++j) {
                if (t[i] == t[j]) {
                    swap(s[i], t[j]);
                    cout << i + 1 << " " << j + 1<< endl;
                    cout << "1 1" << endl;
                    break;
                }
                if (t[i] == s[j]) {
                    swap(s[j], t[j]);
                    swap(s[i], t[j]);
                    cout << j + 1 << " " << j + 1 << endl;
                    cout << i + 1 << " " << j + 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}



