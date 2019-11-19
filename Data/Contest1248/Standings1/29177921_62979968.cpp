#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,n,m,b,sa,sb,sc,sd;
signed main(){
    scanf("%lld",&t);
    for(;t--;){
        sa=sb=sc=sd=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld",&b);
            if(b&1)
                sa++;
            else sb++;
        }
        scanf("%lld",&m);
        for(int i=1;i<=m;i++){
            scanf("%lld",&b);
            if(b&1)
                sc++;
            else sd++;
        }
        printf("%lld\n",sa*sc+sb*sd);
    }
    return 0;
}