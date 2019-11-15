#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define gc getchar
#define il inline
#define re register
#define LL long long
using namespace std;
template <typename T>
void read(T &s)
{
    s = 0;
    bool p = 0;
    char ch;
    while (ch = gc(), p |= ch == '-', !isdigit(ch))
        ;
    while (s = s * 10 + ch - '0', ch = gc(), isdigit(ch))
        ;
    s *= p ? -1 : 1;
}
char s[200000];
int ans = 1;
const int MOD = 1000000007;
int f[200000];
int main()
{
    char ch;
    int len = 0;
    while (ch = gc(), !isalpha(ch))
        ;
    while (s[++len] = ch, ch = gc(), isalpha(ch))
        ;
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= len; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    for (int i = 1; i <= len; ++i)
    {
        if (s[i] == 'm' || s[i] == 'w')
        {
            ans *= 0;
        }
        else if (s[i] == 'n' || s[i] == 'u')
        {
            int cnt = 0, j;
            for (j = i; j <= len; ++j)
                if (s[i] == s[j])
                    ++cnt;
                else
                    break;
            ans = (ans * 1ll * f[cnt]) % MOD;
            if (j == len && s[i] == s[j])
                i = len + 1;
            else
                i = j - 1;
        }
    }
    printf("%d", ans);
    return 0;
}