#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N= 1e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

int main(){
    ll n;
    cin>>n;

    if(n==1)return cout<<"1" , 0;

    ll gcd = n;
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        gcd = __gcd(gcd , __gcd(i,n/i));
    }

    cout<<gcd;


}

