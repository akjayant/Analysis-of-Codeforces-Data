#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ll prime = 1000000007;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ll t;
    cin >> t;
    ll n;
    string s;
    for (int i = 0; i < t; ++i) {
        cin >> n >> s;
        ll f = -1, l = -1;
        for (int j = 0; j < n; ++j) {
            if (f == -1 && s[j] == '1') {
                f = j;
            }
            if (s[j] == '1') {
                l = j;
            }
        }
        if (f == -1) {
            cout << n << '\n';
            continue;
        }
        cout << max(2 * (l + 1), 2 * (n - f)) << '\n';
    }

    return 0;
}
