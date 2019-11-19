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
const int N = 1e3+5;
int n, ans, ansl, ansr, f[N], g[N];
char s[N], t[N];
void update(int l, int r)
{
    int res = 0; g[n+1] = n;
    swap(s[l], s[r]), swap(s[l+n], s[r+n]);
    for(int i = 1; i <= n; ++i) f[i] = f[i-1]+(s[i] == '('?1:-1);
    for(int i = n; i; --i) g[i] = min(g[i+1], f[i]);
    for(int i = n+1, j = 0, k = n; i <= n<<1; ++i)
    {
        j += s[i-n] == '('?1:-1, f[i] = f[i-1]+(s[i] == '('?1:-1);
        k = min(k, f[i]), res += min(k, g[i-n]) == j&&f[i] == j;
    }
    swap(s[l], s[r]), swap(s[l+n], s[r+n]);
    if(ans < res) ans = res, ansl = l, ansr = r;
}
int main()
{
    n = read(), scanf("%s", s+1), ans = 0, ansl = ansr = 1;
    for(int i = 1; i <= n; ++i) s[i+n] = s[i];
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j)
            update(i, j);
    printf("%d\n", ans);
    printf("%d %d\n", ansl, ansr);
    return 0;
}