#include <iostream>

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

#define itn int
#define fro for
#define INF 0x7fffffff
#define lowbit(x) (x & (-x))
#define sze(s) (int)strlen(s)

typedef long long ll;
using namespace std;

/*------------------------------------------------------------------------------------*/
template <typename _t>
inline void read(_t &x){
    x = 0; _t fu = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') fu = - 1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + (ch & 15);
        ch = getchar();
    }
    x *= fu ;
}
/*------------------------------------------------------------------------------------*/
ll gcd(ll x, ll y){return !x? y: gcd(y % x, x);}
void exgcd(ll a, ll b, ll &x, ll &y){
    if(!b){x = 1; y = 0;return;}
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
/*------------------------------------------------------------------------------------*/

int n, m;
const int maxn = 1e5;
const int M = 1e9 + 7;

ll f[2];
ll g[maxn + 10];
ll h[maxn];

ll geth(){
    h[1] = 1; h[2] = 2;
    for(int i = 3; i <= m; i++) h[i] = (h[i - 1] % M + h[i - 2] % M) % M;
    return (h[m] * 2 - 2) % M;
}

void ini(){
    g[1] = 2; g[2] = 4;
    for(int i = 3; i <= n; i++) g[i] = (g[i -1] % M + g[i -2] % M) % M;
    f[1] = geth();
}

//#define LOCAL
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &m);
    ini();
    printf("%lld\n", (f[1] + g[n]) % M);
    return 0;
}
