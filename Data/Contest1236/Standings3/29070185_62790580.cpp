#include<bits/stdc++.h>
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(0);std::cout.tie(0);
#define endl "\n" 
#define FOR(I,N,X) for(int i=I;i<N;i+=X)
#define gcd __gcd 
#define pb push_back 
typedef int itn;
typedef long long  ll;
typedef unsigned long long  ull;
using namespace std;
const ll mod=1000000007;
ll n,m;
ll qpow(ll a,ll b,ll m){
    ll ans=1;
    ll k=a;
    while(b){
        if(b&1)ans=ans*k%m;
        k=k*k%m;
        b>>=1;
    }
    return ans;
}
int main(){
	IOS;
    cin>>n>>m;
    cout<<qpow(qpow(2,m,mod)-1,n,mod)<<endl;
	return 0;
}