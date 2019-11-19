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
const int N = 1e5+5;
int t, n, a[N];
int64 x, y;
int main()
{
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    sort(a+1, a+1+n);
    for(int i = 1; i <= n/2; ++i) x += a[i];
    for(int i = n/2+1; i <= n; ++i) y += a[i];
    printf("%I64d\n", x*x+y*y);
    return 0;
}