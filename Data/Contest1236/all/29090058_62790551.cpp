#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

typedef long long ll;
using namespace std;
const int maxn = 1e6 + 5, mod = 1e9 + 7;
ll qpow(ll a, ll n){
    ll y = a, res = 1;
    while(n){
        if(n&1)res = res*y%mod;
        y = y*y%mod;
        n >>= 1;
    }
    return res;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    cout<<qpow(qpow(2,m)-1,n)<<endl;
    return 0;
}
