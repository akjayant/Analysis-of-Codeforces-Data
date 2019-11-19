#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+50;
typedef long long ll;

ll fac[maxn];
int tot;

int main(){
    //freopen("in.txt","r",stdin);
    ll n;
    while(scanf("%I64d",&n)==1){
        if(1==n){
            puts("1");
            continue;
        }
        ll m=sqrt(n)+0.5;
        tot=0;
        for(ll i=2;i<=m;++i){
            if(n%i==0){
                fac[tot++]=i;
                while(n%i==0) n/=i;
            }
        }
        if(n>1) fac[tot++]=n;
        if(1==tot){
            printf("%I64d\n",fac[0]);
            continue;
        }
        puts("1");
    }
    return 0;
}