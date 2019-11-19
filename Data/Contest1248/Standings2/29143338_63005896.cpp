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
const int N = 1e5+5, P = 1e9+7;
int n, m, g[N], f[N];
int main()
{
    n = read(), m = read();
    f[1] = 2, f[2] = 4;
    for(int i = 3; i <= max(n, m); ++i) f[i] = (f[i-1]+f[i-2])%P;
    g[1] = f[n], g[2] = (f[n]+2)%P;
    for(int i = 3; i <= max(n, m); ++i) g[i] = (g[i-1]+f[i-2])%P;
    printf("%d\n", g[m]);
    return 0;
}