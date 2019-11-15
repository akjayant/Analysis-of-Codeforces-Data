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

        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.rbegin(), a.rend());

        ll answer = 0;
        while (answer < n &&  a[answer] > answer) {
            ++answer;
        }

        cout << answer << endl;
    }
    return 0;
}