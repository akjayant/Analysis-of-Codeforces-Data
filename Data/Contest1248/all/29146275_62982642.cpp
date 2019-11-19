#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int t1=0,t2=0;
        int p1=0,p2=0;
        int n,m,temp;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&temp);
            if(0==temp%2) t1++;
            else t2++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&temp);
            if(0==temp%2) p1++;
            else p2++;
        }
        ll ans=0;
        ans=(ll)p1*t1+(ll)p2*t2;
        printf("%lld\n",ans);
    }
    return 0;
}
