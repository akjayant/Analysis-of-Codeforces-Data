#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,M;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    M;
    ll a=2;
    ll ans = 1;
    ll MA = 1000000007;
    for(;M>0 ; M>>=1){
        if(M&1ll){
            ans*=a;
        }
        ans%=MA;
        a*=a;
        a%=MA;
    }
    ans--;
    a = ans;
    ans = 1;
    for(;N>0 ; N>>=1){
        if(N&1ll){
            ans*=a;
        }
        ans%=MA;
        a*=a;
        a%=MA;
    }
    cout<<ans;
}