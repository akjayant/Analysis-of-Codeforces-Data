#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],n,m;
int c1,c2,d1,d2;
void solve(){
    c1=c2=d1=d2=0;
    scanf("%d",&n);
    for(int i=1,x;i<=n;++i){
        scanf("%d",&x);
        if(x%2==0)++c1;
        else ++c2;
    }
    scanf("%d",&m);
    for(int i=1,x;i<=m;++i){
        scanf("%d",&x);
        if(x%2==0)++d1;
        else ++d2;
    }
    printf("%lld\n",1ll*d1*c1+1ll*d2*c2);
}
int main(){
    int T;
    scanf("%d",&T);
    for(;T--;)solve();

    return 0;
}