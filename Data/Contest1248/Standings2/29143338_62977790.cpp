#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
typedef long long int64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
int t, n, m;
int64 cnt[2][2], ans;
int main()
{
    t = read();
    while(t--)
    {
        n = read(), ans = 0, memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; ++i) ++cnt[0][read()&1];
        m = read();
        for(int i = 1; i <= m; ++i) ++cnt[1][read()&1];
        ans = cnt[0][0]*cnt[1][0]+cnt[0][1]*cnt[1][1];
        printf("%I64d\n", ans);
    }
    return 0;
}