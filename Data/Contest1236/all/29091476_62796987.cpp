#include <bits/stdc++.h>
#define MOD 1000000007
#define MOD1 998244353
#define ll long long int
#define endl "\n"
#define INF 1e+18
#define INF1 1e+9
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define debx cout<<" X "<<endl;
#define deby cout<<" Y "<<endl;
#define debz cout<<" Z "<<endl;
using namespace std;

ll mpow(ll a, ll b){
    if(!b)
        return 1;
    ll temp=mpow(a,b/2);
    temp=(temp*temp)%MOD;
    if(b%2)
        return (a*temp)%MOD;
    return temp;
}
ll fn(ll a, ll b){
    if(a%b)
        return 1+a/b;
    return a/b;
}
int main(){
    fastio;
    ll n;
    cin>>n;
    vector<ll> a[n*n+5];
    ll flag=1;
    for(ll i=0;i<n*n;i++){
        if(i%n==0)
            flag=!flag;
        if(flag)
            a[i%n].pb(i+1);
        else
            a[n-i%n-1].pb(i+1);
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<a[i].size();j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
