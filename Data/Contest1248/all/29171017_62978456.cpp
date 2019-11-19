#include<bits/stdc++.h>
using namespace std;
typedef long long L;

int main()
{
    int t;scanf("%d",&t);

    while(t--){
        L n,d,m,j1=0,o1=0,j2=0,o2=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&d);
            if(d&1){
                j1++;
            } else {
                o1++;
            }
        }
        scanf("%lld",&m);
        for(int i=1;i<=m;i++){
            scanf("%lld",&d);
            if(d&1){
                j2++;
            } else {
                o2++;
            }
        }
        printf("%lld\n",1ll*(1ll*j1*j2+1ll*o1*o2));

    }
    return 0;
}
