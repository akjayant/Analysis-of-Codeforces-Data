#include <bits/stdc++.h>

using namespace std;
long long n,m,mod,kq;
long long lt(long long x,long long y)
{
    if (y==0) return 1;
    if (y==1) return x;
    long long k=lt(x,y/2);
    if (y%2) return k*k%mod*x%mod;
             return k*k%mod;
}
int main()
{
    cin>>n>>m;
    mod=1000000007;
    kq=(lt(2,m)-1+mod)%mod;
    kq=lt(kq,n);
    cout<<kq;
    return 0;
}
