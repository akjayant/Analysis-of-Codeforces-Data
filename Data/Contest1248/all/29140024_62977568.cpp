#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
     int T;
     scanf("%d",&T);
     while(T--){
        int n;
        scanf("%d",&n);
        int p,q;
        int ji=0;
        int ou=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&p);
            if(p%2==0){
                ou++;
            }else ji++;
        }
        ll ans=0;
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&q);
            if(q%2==0){
                ans+=ou;
            }else ans+=ji;
        }
        printf("%lld\n",ans);
     }
}