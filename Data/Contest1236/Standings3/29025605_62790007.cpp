#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL mod=1e9+7;
LL qpow(LL a,LL x) {
    LL res=1;
    while(x) {
        if(x&1) res=res*a%mod;
        a=a*a%mod;
        x>>=1;
    }
    return res;
}
int main() {
    int n,m;
    cin>>n>>m;
    cout<<qpow(qpow(2,m)-1,n)<<endl;
    return 0;
}
