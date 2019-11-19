#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000000+10;
int main()
{
    ll n;
    scanf("%lld",&n);
    ll sum=0,x;
    // ll nn=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            sum++;
            x=i;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) {
        sum++;
        x=n;
    }
    if(sum==1) printf("%lld\n",x);
    else printf("1\n");
    return 0;
}
