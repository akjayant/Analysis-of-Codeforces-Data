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

int n, m, t[2][2];

int main() {
    //freopen("in", "r", stdin);
    int tim = in();
    while (tim--) {
        memset(t, 0, sizeof(t));
        n = in();
        for (int i = 1; i <= n; ++i) {
            ++t[0][in() % 2];
        }
        m = in();
        for (int i = 1; i <= m; ++i) {
            ++t[1][in() % 2];
        }
        printf("%lld\n", 1ll * t[0][0] * t[1][0] + 1ll * t[0][1] * t[1][1]);
    }
    return 0;
}
