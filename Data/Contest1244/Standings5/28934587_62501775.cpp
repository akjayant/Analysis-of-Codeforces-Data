#define mm(a) memset(a,0,sizeof(a));
#define max(x, y) (x)>(y)?(x):(y)
#define min(x, y) (x)<(y)?(x):(y)
#define Fopen freopen("1.in","r",stdin); freopen("m.out","w",stdout);
#define rep(i, a, b) for(int i=(a);i<=(b);i++)
#define per(i, b, a) for(int i=(b);i>=(a);i--)
#define PII pair<ll,ll>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5+5;
const ll mod = 1e9+7;

int n;
ll k,a[MAXN],pre[MAXN];
int main() {
    scanf("%d%lld",&n,&k);
    for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll l=1,r=n,cntl=1,cntr=1;
    while(l<r){
        if(cntl<=cntr) {
            if(cntl*(a[l+1]-a[l])<=k) {
                k-=cntl*(a[l+1]-a[l]);
                cntl++;
                l++;
            }
            else {
                break;
            }
        } else {
            if(cntr*(a[r]-a[r-1])<=k) {
                k-=cntr*(a[r]-a[r-1]);
                cntr++;
                r--;
            }
            else {
                break;
            }
        }
    }
    if(cntl<=cntr) a[l]+=k/cntl;
    else a[r]-=k/cntr;
//    printf("%d %d %d %d\n",l,r,a[l],a[r]);
    printf("%lld\n",a[r]-a[l]);
    return 0;
}
