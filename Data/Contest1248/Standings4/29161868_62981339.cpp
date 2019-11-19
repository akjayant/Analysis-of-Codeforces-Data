#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100005;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&x);
            if(x%2!=0) cnt1++;
            else cnt2++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            scanf("%d",&x);
            if(x%2!=0) cnt3++;
            else cnt4++;
        }
        long long  ans=0;
        ans=(long long )cnt1*cnt3+(long long )cnt2*cnt4;
        printf("%lld\n",ans);
    }
    return 0;
}

