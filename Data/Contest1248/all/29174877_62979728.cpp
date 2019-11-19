#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;
int n,m,k;
ll x,y,uuu;
int main(){
    int i,j,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        x=0,y=0;
        for(int i=1;i<=n;i++){
            scanf("%I64d",&uuu);
            if(uuu%2==0)
                x++;
            else
                y++;
        }
        ll xx=0,yy=0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            ll u;
            scanf("%I64d",&u);
            if(u%2==0)
                xx++;
            else
                yy++;
        }
        ll ans=0;
        ans+=xx*x+yy*y;
        printf("%I64d\n",ans);
    }
    return 0;
}
