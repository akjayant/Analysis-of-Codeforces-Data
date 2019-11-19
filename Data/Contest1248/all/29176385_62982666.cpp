#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
int n;
signed main(){
    int T;scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);int cnt1=0,cnt2=0,cnt3=0,cnt4=0,x;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            if(abs(x)%2==0)cnt1++;
            else cnt2++;
        }scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x);
            if(abs(x)%2==0)cnt3++;
            else cnt4++;
        }printf("%lld\n",cnt1*cnt3+cnt2*cnt4);
    }
    return 0;
}