#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 100005
int n; int m;
ll f[100005];
ll ans;





int main(){
    scanf("%d %d",&n,&m);
    if(n==1&&m==1){
        printf("2\n");
        return 0;
    }
    int mx=max(n,m);
    f[0]=1; f[1]=1;
    for(int i=2;i<=mx;++i) f[i]=(f[i-1]+f[i-2])%mod;
    ans=(ans+2*f[n])%mod; ans=(ans+2*f[m])%mod;
    ans=((ans-2)%mod+mod)%mod;
    printf("%lld\n",ans);
    return 0;
}



















