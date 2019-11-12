#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;

ll B=1000000007;

ll get(ll now,ll n){
    if(now==0)return 1;
    if(now==1)return n;
    ll x=get(now/2,n);
    x=x*x;
    x%=B;
    if(now%2)x*=n;
    x%=B;
    return x;
}



int main(){
    ll i,j,k,a,b,c,n,m,t,x,y;
    scanf("%lld%lld",&n,&m);
    printf("%lld",get(n,get(m,2)-1));
}
