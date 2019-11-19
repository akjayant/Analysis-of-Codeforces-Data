#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nt(ll a)
{
    if(a<2) return 1;
    if(a==2||a==3||a==5||a==7) return 1;
    if(a%2==0) return 2;
    ll s=sqrt(a);
    for(ll i=3;i<=s;i+=2)
    {
        if(a%i==0) return i;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll t1=nt(n);
    if(t1==1) {cout<<n;return 0;}
    while(n%t1==0) n/=t1;
    if(n!=1) cout<<1;
    else cout<<t1;
    return 0;
}
