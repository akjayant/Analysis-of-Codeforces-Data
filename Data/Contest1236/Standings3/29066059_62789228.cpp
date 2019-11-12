#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<vector>
#include<stack>
#define Lson root << 1
#define Rson root << 1 | 1
#define mid (l+r)/2
#define Length(x) (tree[x].R - tree[x].L + 1)
#define bug puts("**********");
#define debug(x) cout<<"["<<x<<"]" <<endl;
#define IO ios::sync_with_stdio(false),cin.tie(0);
#define Fin freopen("C://Users//z1286//Desktop//in.txt", "r", stdin);
#define Fout freopen("C://Users//z1286//Desktop//out.txt","w",stdout);
using namespace std;
typedef long long ll;
const int INF = 0x7fffffff;
const int MaxN = 1e5 + 5;
const int MaxM = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
const double eps = 1e-8;
inline ll read(){
    ll x = 0, flag = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') flag = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){ x = x * 10 + ch - '0'; ch = getchar();}
    return flag * x;
}
ll pow_mod(ll a, ll n){
    ll ans = 1;
    ll temp = a % mod;
    while(n){
        if(n & 1){
            ans *= temp;
            ans %= mod;
        }
        n >>= 1;
        temp *= temp;
        temp %= mod;
    }
    return ans;
}
ll N, M;
int main(){
    while(~scanf("%lld%lld", &N, &M)){
        ll a = (pow_mod(2, M) - 1 + mod) % mod;
        ll ans = pow_mod(a, N);
        printf("%lld\n", ans);
    }
}









