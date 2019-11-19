#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ll T;
    scanf("%lld",&T);
    while(T--){
        ll a1=0,a2=0,b1=0,b2=0;
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            ll t;scanf("%lld",&t);
            if(t&1) a1++;
            else a2++;
        }
        int m;scanf("%d",&m);
        for(int i=1;i<=m;i++){
            ll t;scanf("%lld",&t);
            if(t&1) b1++;
            else b2++;
        }
        printf("%lld\n",a1*b1+a2*b2);
    }
    return 0;
}
