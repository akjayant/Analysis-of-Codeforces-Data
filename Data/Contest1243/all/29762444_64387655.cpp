#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    scanf("%lld",&n);
    ll t=n;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            t=__gcd(t,i);
            t=__gcd(t,n/i);
        }
    }
    printf("%lld\n",t);
    return 0;
}
