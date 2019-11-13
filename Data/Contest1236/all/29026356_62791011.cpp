#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<vector>
#include<map>
#include<functional>
#include<bitset>
    
#define fst first
#define sc second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define lc root<<1
#define rc root<<1|1
#define lowbit(x) ((x)&(-x)) 

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
typedef pair<ll,ll> PLL;

const db eps = 1e-6;
const int mod = 1e9+7;
const int maxn = 5e5+100;
const int maxm = 2e6+100;
const int inf = 0x3f3f3f3f;
const db pi = acos(-1.0);

ll fp(ll a, ll n){
    ll ans = 1;
    while(n){
        if(n & 1) ans *= a;
        a *= a;
        a %= mod;
        n >>= 1;
        ans %= mod;
    }
    return ans;
}

ll n,m;
int main(){
    scanf("%lld %lld", &n, &m);
    ll tmp = fp(2,m)+mod-1;
    tmp%=mod;
    printf("%lld",fp(tmp,n)%mod);
    return 0;
}