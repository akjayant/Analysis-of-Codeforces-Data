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
const int MAXN = 200;
int s[MAXN];
int out[MAXN];
int a[4];
int b[4];
int qwq[4] = {0, 2, 3, 1}; // b 需要的 a
int main()
{
    int t;
    read(t);
    while (t--)
    {
        int n;
        read(n);
        for (int i = 1; i <= 3; ++i)
            a[i] = b[i] = 0;
        for (int i = 1; i <= 3; ++i)
            read(a[i]);
        for (int i = 1; i <= n; ++i)
        {
            char ch;
            while (ch = gc(), !isalpha(ch))
                ;
            if (ch == 'R')
                ++b[1], s[i] = 1;
            else if (ch == 'P')
                ++b[2], s[i] = 2;
            else
                ++b[3], s[i] = 3;
        }
        int win = min(a[1], b[3]) + min(a[2], b[1]) + min(a[3], b[2]);
        if (win >= (n - (n >> 1)))
        {
            int cnt[4] = {0, 0, 0, 0};
            for (int i = 1; i <= n; ++i)
            {
                int ned = qwq[s[i]];
                if (cnt[ned] + 1 <= a[ned])
                    ++cnt[ned], out[i] = ned;
                else
                    out[i] = 10;
            }
            for (int i = 1; i <= n; ++i)
            {
                if (out[i] == 10)
                {
                    for (int j = 1; j <= 3; ++j)
                        if (cnt[j] < a[j])
                        {
                            ++cnt[j], out[i] = j;
                            break;
                        }
                }
            }
            printf("YES\n");
            for (int i = 1; i <= n; ++i)
                if (out[i] == 1)
                    printf("R");
                else if (out[i] == 2)
                    printf("P");
                else
                    printf("S");
            printf("\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}