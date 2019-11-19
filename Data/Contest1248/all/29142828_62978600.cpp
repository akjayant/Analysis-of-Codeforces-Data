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


//#define LOCAL
int main(){
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        itn x;
        ll odd1, even1, odd2, even2;
        odd1 = odd2 = even1 = even2 = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            if(x & 1) odd1++;
            else even1++;
        }
        int m; scanf("%d", &m);
        for(int i =0;  i< m; i++){
            scanf("%d", &x);
            if(x & 1) odd2++;
            else even2++;
        }
        printf("%lld\n", odd1 * odd2 + even1 * even2);
        
        
    }
    return 0;
}
