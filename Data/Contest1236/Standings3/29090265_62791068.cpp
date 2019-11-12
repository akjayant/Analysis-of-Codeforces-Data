#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll t,n,m;
ll sq(ll x){
    return (x*x)%MOD;
}
ll bmod(ll a,ll b){
    if(b==0){
        return 1;
    } else if(b%2==0){
        return sq(bmod(a,b/2));
    } else {
        return (a*bmod(a,b-1))%MOD;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll x=bmod(2,m);
    x=x+MOD-1;
    x%=MOD;
    cout<<bmod(x,n);
    return 0;
}