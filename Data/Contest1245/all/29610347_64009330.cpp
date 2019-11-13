#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll D = 100007;
const ll modulo = 1000000007;

ll fib[D];

int main()
{
    string s;
    cin >> s;
    ll n = s.length();

    for (ll i = 0; i < n; i++)
        if (s[i] == 'm' || s[i] == 'w')
            cout << 0 << endl, exit(0);

    fib[0] = fib[1] = 1;
    for (ll i = 2; i <= n; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % modulo;

    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll cnt = 1;
        while ((i <= n) && (s[i] == s[i - 1]) && (s[i] == 'n' || s[i] == 'u'))
            cnt++, i++;
        ans = (ans * fib[cnt]) % modulo;
    }
    cout << ans << endl;
    return 0;
}
