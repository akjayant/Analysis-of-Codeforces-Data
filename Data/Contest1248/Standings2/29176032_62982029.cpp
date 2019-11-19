#include<bits/stdc++.h>
using namespace std;
int ans;
int p[100500],c[100500];
int main(){
    int tt,n,m;
    scanf("%d",&tt);
    while (tt--){
        c[0]=c[1]=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            scanf("%d",&p[i]);
            c[p[i]&1]++;
        }
        long long ans=0;
        scanf("%d",&m);
        for (int i=1;i<=m;i++){
            int x; scanf("%d",&x);
            ans+=c[x&1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}