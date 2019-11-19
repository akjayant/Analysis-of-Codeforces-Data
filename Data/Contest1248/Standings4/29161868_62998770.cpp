#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll mod =1000000007;
const int maxn = 100005;
ll f[maxn];
int main(){
    f[1]=2;f[2]=4;
    for(int i=3;i<100005;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    int n,m;
    scanf("%d%d",&n,&m);
    ll ans=(f[m]+f[n]-2ll+mod)%mod;
    printf("%I64d\n",ans);
    return 0;
}

