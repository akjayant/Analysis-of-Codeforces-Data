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

/*----------------------------QUICK_READ----------------------------------------------*/
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


const int M = 1e9 + 7;

//a^b
ll quick(ll a, ll b){
    ll ans = 1, res = a;
    while(b){
        if(b & 1){
            ans *= res;
            ans %= M;
        }
        res *= res; res %= M;
        b >>= 1;
    }
    return ans % M;
}

//#define LOCAL
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ll n, m; scanf("%lld %lld", &n, &m);
    printf("%lld\n", quick(quick(2, m) - 1, n));
    
    return 0;
}
