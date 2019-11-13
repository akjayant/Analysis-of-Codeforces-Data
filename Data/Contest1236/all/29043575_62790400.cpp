#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9+7;
typedef long long LL;

LL pow(LL x,LL n){
    LL ret = 1;
    while(n){
        if(n&1){
            ret = ret*x%mod;
        }
        x = x*x%mod;
        n>>=1;
    }
    return ret;
}
int main()
{
    LL n,m;
    cin>>n>>m;
    LL ans = pow(pow(2,m)-1,n);
    cout<<ans<<endl;
    return 0;
}
