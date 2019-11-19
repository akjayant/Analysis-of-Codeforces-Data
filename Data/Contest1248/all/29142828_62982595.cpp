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

const int maxn = 1e5 + 10;
itn a[maxn];

//#define LOCAL
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    int top = n / 2 - 1;
    ll res1, res2; res1 = res2 = 0;
    for(int i = 0; i <= top; i++)
        res1 += a[i];
    for(int i = top + 1; i < n; i++)
        res2 += a[i];
    printf("%lld\n", res1 * res1  +res2 * res2);
    return 0;
}
