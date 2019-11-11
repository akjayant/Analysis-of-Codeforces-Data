#include<bits/stdc++.h>
using namespace std;
const long MOD = 1e9 + 7;
string s;
long long f[100005];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for (long i = 3; i <= 1e5; i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    for (long i = 0; i < s.size(); i++)
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            cout << 0;
            return 0;
        }
    }
    long cnt = 0;
    long long res = 1;
    s = s + '@';
    for (long i = 0; i < s.size(); i++)
    {
        if (s[i] == 'u') cnt++;
        if (s[i] != 'u')
        {
            if (cnt > 1)
            {
                res = (res * f[cnt]) % MOD;
            }
            cnt = 0;
        }
    }
    cnt = 0;
    for (long i = 0; i < s.size(); i++)
    {
        if (s[i] == 'n') cnt++;
        if (s[i] != 'n')
        {
            res = (res * f[cnt]) % MOD;
            cnt = 0;
        }
    }
    cout << res;
}
