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

int main(){
    fastio;
    ll n,m;
    cin>>n>>m;
    ll temp=mpow(2,m)-1;
    temp=mpow(temp,n);
    cout<<temp;
}
