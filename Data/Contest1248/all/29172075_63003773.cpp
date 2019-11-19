#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
typedef long long ll;
typedef double db;
inline int in() {
	int x=0;char c=getchar();bool f=0;
	while(c<'0'||c>'9') f|=c=='-', c=getchar();
	while(c>='0'&&c<='9') x=x*10+(c^48), c=getchar();
	return f?-x:x;
}
inline long long lin() {
	long long x=0;char c=getchar();bool f=0;
	while(c<'0'||c>'9') f|=c=='-', c=getchar();
	while(c>='0'&&c<='9') x=x*10+(c^48), c=getchar();
	return f?-x:x;
}

const int N = (int)1e5 + 5, mod = 1e9 + 7;

int n, m;
int f[N];

int main() {
    //freopen("in", "r", stdin);
    n = in(), m = in();
    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n || i <= m; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    printf("%d\n", (f[n] + f[m] - 1) % mod * 2 % mod);
    return 0;
}
