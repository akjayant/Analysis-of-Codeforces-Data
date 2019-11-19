#include <bits/stdc++.h>  
#define N 100005
#define pb push_back
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll n;
vector<ll> v;

void f(ll x,ll y){
    if(x==1) return;
    for(ll i=y;i*i<=x;i++){
        ll k=x;
        if(k%i!=0) continue;
        while(1){
            k/=i;
            if(k%i!=0) break;
        }
        v.pb(i);
        f(k,y+1);
        return;
    }
    if(x!=1) v.pb(x);
    return;
}
ll gcd(ll a,ll b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int main(){
    fastio;
    cin>>n;
    if(n==1){
        cout<<"1";
        return 0;
    }
    f(n,2);
    ll x=v[0];
    for(int i=0;i<v.size();i++){
        for(int j=0;j<i;j++){
            x=gcd(x,v[i]-v[j]);
        }
    }
    cout<<x;
    return 0;
}