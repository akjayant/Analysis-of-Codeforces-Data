#include "bits/stdc++.h"
#define hhh printf("hhh\n")
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}

const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;

ll n, p, a, b;

ll gcd(ll a, ll b) { return b==0?a:gcd(b,a%b); }

void solve() {
    ll x=p/a, y, s=p%a;
    if(s==0) {
        if(x<=n) printf("%lld %lld %lld\n", x, 0ll, n-x);
        else printf("-1\n");
        return;
    }
    while(x>=0) {
        y=s/b;
        if(s%b==0) {
            if(x+y<=n) printf("%lld %lld %lld\n", x, y, n-x-y);
            else printf("-1\n");
            return;
        }
        if(x+y>n) { printf("-1\n"); return; }
        x--;
        s+=a;
    }
    printf("-1\n");
}

int main() {
    cin>>n>>p>>a>>b;
    ll c=gcd(a,b);
    if(p%c) return printf("-1\n"), 0;
    solve();
}