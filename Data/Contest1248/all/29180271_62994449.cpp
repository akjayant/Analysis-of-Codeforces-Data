#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

const int N=2e5+100,mod=1e9+7;
ll fib[N];
int32_t main(){
    fib[0]=1;
    fib[1]=1;
    for (int i=2;i<N;i++){
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]%=mod;
    }
    ll n,m;
    cin >> n >> m;
    ll ans=fib[n]+fib[m];
    ans*=2;
    ans-=2;
    ans+=mod;
    ans%=mod;
    cout << ans;
}

























