#include<bits/stdc++.h>
using namespace std;
#define ll  long long

int isprime(ll x){
    if(x<=1)return 0;
    if(x==2)return 1;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}

int main(){
    ll n;
    cin>>n;
    if(isprime(n))cout<<n<<endl;
    else {
        ll gcd=n;
        for(ll i=1;i*i<=n;i++){
            if(i==1||n%i!=0)continue;
            gcd=__gcd(gcd,i);
            gcd=__gcd(gcd,n/i);
        }
        cout<<gcd<<endl;
    }
    return 0;
}