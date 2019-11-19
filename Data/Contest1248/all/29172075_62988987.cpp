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

int n, t1, t2;
int a[100005];

int main() {
    //freopen("in", "r", stdin);
    n = in();
    for (int i = 1; i <= n; ++i)
        a[i] = in();
    std::sort(a + 1, a + 1 + n);
    for (int i = 1; i * 2 <= n; ++i)
        t1 += a[i];
    for (int i = n / 2 + 1; i <= n; ++i)
        t2 += a[i];
    printf("%lld\n", 1ll * t1 * t1 + 1ll * t2 * t2);
    return 0;
}
