/// I won't go back on my words ... that's my ninja way !!!
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5 ;
int t ,n ,x ,cnt[2][2] ;
int main(){
    scanf("%d",&t);
    while(t--){
        memset(cnt,0,sizeof cnt);
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            ++cnt[0][x%2];
        }
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            ++cnt[1][x%2];
        }
        long long ans = 1ll*cnt[0][0]*cnt[1][0] +  1ll*cnt[0][1]*cnt[1][1] ;
        printf("%lld\n",ans);
    }
    return 0;
}
