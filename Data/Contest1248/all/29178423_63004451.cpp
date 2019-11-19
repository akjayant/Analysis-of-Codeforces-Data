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

ll mod_in(ll n){
    return mpow(n,MOD-2);
}

ll fn(ll a, ll b){
    if(a%b)
        return 1+a/b;
    return a/b;
}

int main(){
   //  fastio;
//    ll t;cin>>t;while(t--){
    ll n,m;
    cin>>n>>m;
    ll maxx=max(n,m);
    ll fact[maxx+5],i;
    fact[0]=1;
    for(i=1;i<maxx+5;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
    }
    ll ans=0;
    for(ll i=1;2*i<=n;i++){
        if(n-2*i==0){
            if(i==1){
                ans++;
                continue;
            }
        }/*
        if(n-2*i-1>=i){
            ll temp1=fact[n-2*i-1];
            ll temp2=mod_in(fact[i]);
            ll temp3=mod_in(fact[n-3*i-1]);
            ans+=(((temp1*temp2)%MOD)*temp3)%MOD;
            ans%=MOD;
        }
        if(n-2*i-1>=i-1 && i>=1){
            ll temp1=fact[n-2*i-1];
            ll temp2=mod_in(fact[i-1]);
            ll temp3=mod_in(fact[n-3*i]);
            ans+=2*((((temp1*temp2)%MOD)*temp3)%MOD);
            ans%=MOD;
        }
        if(n-2*i+1>=i-2 && i>=2){
            ll temp1=fact[n-2*i-1];
            ll temp2=mod_in(fact[i-2]);
            ll temp3=mod_in(fact[n-3*i+1]);
            ans+=(((temp1*temp2)%MOD)*temp3)%MOD;
            ans%=MOD;
        }*/
        if(n-i>=i){
            ll temp1=fact[n-i];
            ll temp2=mod_in(fact[i]);
            ll temp3=mod_in(fact[n-2*i]);
            ans+=(((temp1*temp2)%MOD)*temp3)%MOD;
            ans%=MOD;
        }
    }
   // cout<<"  "<<ans<<endl;
    for(ll i=1;2*i<=m;i++){
       /* if(m-2*i==0 && m==2){
            ans++;
            continue;
        }
        if(m-2*i-1>=i){
            ll temp1=fact[m-2*i-1];
            ll temp2=mod_in(fact[i]);
            ll temp3=mod_in(fact[m-3*i-1]);
            ans+=(((temp1*temp2)%MOD)*temp3)%MOD;
            ans%=MOD;
        }
        if(m-2*i-1>=i-1){
            ll temp1=fact[m-2*i-1];
            ll temp2=mod_in(fact[i-1]);
            ll temp3=mod_in(fact[m-3*i]);
            ans+=2*((((temp1*temp2)%MOD)*temp3)%MOD);
            ans%=MOD;
        }
        if(i>1 && m-2*i-1>=i-2){
            ll temp1=fact[m-2*i-1];
            ll temp2=mod_in(fact[i-2]);
            ll temp3=mod_in(fact[m-3*i+1]);
            ans+=(((temp1*temp2)%MOD)*temp3)%MOD;
            ans%=MOD;
        } */
        if(m-i>=i){
     //       cout<<m-i+1<<" "<<fact[m+1-i]<<"   "<<i<<" "<<fact[i]<<"    "<<m-2*i+1<<" "<<fact[m-2*i+1]<<endl;
            ll temp1=fact[m-i];
            ll temp2=mod_in(fact[i]);
            ll temp3=mod_in(fact[m-2*i]);
            ans+=(((temp1*temp2)%MOD)*temp3)%MOD;
            ans%=MOD;
       //     cout<<i<<"  "<<ans<<" "<<(temp1*temp2*temp3)%MOD<<endl;
        }
    }
   // cout<<"  "<<ans<<endl;
    ans*=2;
    ans+=2;
    ans%=MOD;
    cout<<ans;
}

