#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long
#define pb push_back
#define ft first
#define sd second
#define inf (int)1e9

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);

    ll k;

    cin >> k;

    for (ll x = 0; x < k; x++) {
        ll n;

        string s,t;

        cin >> n;

        cin >> s >> t;
        vector <pair<ll,ll>> an;

        for (ll i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                bool f = 0;
                for (ll j = i + 1; j < n; j++) {
                    if (s[i] == s[j]) {
                        f = 1;
                        an.pb({j,i});
                        swap(s[j],t[i]);
                        break;
                    }
                }

                if (!f) {
                    for (ll j = i + 1; j < n; j++) {
                        if (s[i] == t[j]) {
                            an.pb({n-1,j});
                            swap(s[n-1],t[j]);
                            an.pb({n-1,i});
                            swap(s[n-1],t[i]);
                            break;
                        }
                    }
                }
            }
        }

        if (s != t) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";

            cout << an.size() << '\n';

            for (auto i: an) {
                cout << i.ft+1 << ' ' << i.sd + 1 << '\n';
            }
        }
    }
    return 0;
}