#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double pi = acos(-1.0);
#define eps 10e-8
const ll mod = 1e9 + 7;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll inverse(ll a) { return a == ll(1) ? ll(1) : (mod - mod / a) * inverse(mod % a) % mod; } // 求逆元
const int MAXN = 1e6 + 5;
const int MAXM = 2 * MAXN;
const int INF = 0x3f3f3f3f;
//clock_t c1 = clock(); //测时间
//std::cerr << "Time:" << clock() - c1 <<"ms" << std::endl;
//=======================================================================//

int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int ans=0;
        while (c>=2&&b>=1){
            ans+=3;
            c-=2;
            b-=1;
        }
        while (b>=2&&a>=1){
            ans+=3;
            a-=1;
            b-=2;
        }
        printf("%d\n",ans);
    }    
    return 0;
}