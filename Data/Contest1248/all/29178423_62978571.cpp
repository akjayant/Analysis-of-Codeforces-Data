#include <bits/stdc++.h>
#define MOD 1000000007
#define MOD1 998244353
#define ll long long int
#define endl "\n"
#define INF 1e+18
#define INF1 1e+9
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
//#define mp make_pair
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
    ll a[n],i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll sum1=0,sum2=0;
    for(i=0;i<n/2;i++)
        sum1+=a[i];
    for(i=n/2;i<n;i++)
        sum2+=a[i];
    cout<<sum1*sum1+sum2*sum2<<endl;
}
