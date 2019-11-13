#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn=1e5+5;

ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        if(gcd(a,b)==1)printf("Finite\n");
        else printf("Infinite\n");
    }
    return 0;
}
