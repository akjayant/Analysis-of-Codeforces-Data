#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll inv(ll x){
    return power(x,mod-2);
}
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int a[111111];
int main(){
    int x,y;
    cin>>x>>y;
    cout<<power((power(2,y)-1),x);

}
