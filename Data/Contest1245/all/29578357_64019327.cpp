#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pll pair<ll, ll>

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    vector<ll> fib(100006);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < fib.size(); i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    }

    int i = 0, j;
    ll res = 1;
    while (i < s.size()) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << "0\n";
            return 0;
        }
        if (s[i] != 'n' && s[i] != 'u') {
            i++;
            continue;
        }

        j = i+1;
        while (j < s.size() && s[j] == s[i]) {
            j++;
        }
        res = (res * fib[j - i]) % MOD;
        i = j;
    }
    cout << res << "\n";

    return 0;
}