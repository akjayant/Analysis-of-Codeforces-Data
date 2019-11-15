#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll fibo[N];
    fibo[0]=fibo[1]=1;
    for(ll i=2;i<N;i++)fibo[i] = (fibo[i-1] + fibo[i-2])%mod;

    string str;
    cin>>str;

    ll n = str.size();
    for(ll i=0;i<n;i++)if(str[i]=='m' || str[i]=='w')return cout<<"0" , 0;

    ll ans=1 , cnt=0;
    for(ll i=0;i<n;i++){
        if(str[i]!='n'){
            ans = ( ans * fibo[cnt] )%mod;
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    ans = (ans * fibo[cnt])%mod;

    cnt = 0;
    for(ll i=0;i<n;i++){
        if(str[i]!='u'){
            ans = ( ans * fibo[cnt] )%mod;
            cnt=0;
        }
        else{
            cnt++;
        }
    }
    ans = (ans * fibo[cnt])%mod;

    cout<<ans;
}

