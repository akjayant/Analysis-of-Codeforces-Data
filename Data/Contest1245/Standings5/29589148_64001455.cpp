#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int fib[100001] = {};
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 100000; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

    int ans = 1;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'u')
        {
            int cnt = 0;
            while (s[i] == 'u' && i < s.size())
                cnt++, i++;
            i--;
            ans = ans * fib[cnt] % MOD;
        }
        else if (s[i] == 'n')
        {
            int cnt = 0;
            while (s[i] == 'n' && i < s.size())
                cnt++, i++;
            i--;
            ans = ans * fib[cnt] % MOD;
        }
        else if (s[i] == 'm' || s[i] == 'w')
            return cout << "0\n", 0;
        else;
    cout << ans << '\n';

    return 0;
}

//      *   *  *****  *   *  *   *
//     *   *  *      **  *  *   *
//    *****  *****  * * *  *   *
//   *   *      *  *  **  *   *
//  *   *  *****  *   *   ***
//     *****  *****  *****
//    *      *   *  *
//   *      *****  *
//  *      *  *   *
//  ***** *   *   *****
