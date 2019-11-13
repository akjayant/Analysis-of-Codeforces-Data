#include <bits/stdc++.h>

using namespace std;
#define taskname "cf1245"
const int mod = 1e9 + 7;

int n;
string s;
int64_t f[100005];

int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++)
        if (s[i] == 'w' || s[i] == 'm')
            return cout << 0, 0;
    int64_t res = 1;
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    int pos = 1;
    s += '1';
    while (2)
    {
        if (pos > n)
            break;
        if (s[pos] == 'n' && s[pos + 1] == 'n')
        {
            int cnt = 2;
            pos += 2;
            while (pos <= n && s[pos] == 'n')
            {
                cnt++;
                pos++;
            }
            res = res * f[cnt] % mod;
            continue;
        }
        if (s[pos] == 'u' && s[pos + 1] == 'u')
        {
            int cnt = 2;
            pos += 2;
            while (pos <= n && s[pos] == 'u')
            {
                cnt++;
                pos++;
            }
            res = res * f[cnt] % mod;
            continue;
        }
        pos++;
    }
    cout << res;
}
