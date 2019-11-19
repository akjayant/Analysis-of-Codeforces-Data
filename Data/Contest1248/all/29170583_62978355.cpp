#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        scanf("%d",&n);
        ll p,q,s11=0,s12=0,s21=0,s22=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&p);
            if(p&1)s11++;
            else s12++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&q);
            if(q&1)s21++;
            else s22++;
        }
        ll ans=s11*s21+s12*s22;
        printf("%I64d\n",ans);
    }
}
