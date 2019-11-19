#include <bits/stdc++.h>
using namespace std;
int n,m;
long long fib[100009],mod=1e9+7,a[100009];
int main()
{
    cin>>n>>m;
    if(n<m)swap(n,m);
    fib[1]=2;
    fib[2]=4;
    for(int i=3;i<=n+1;i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    a[1]=fib[n];
    a[2]=a[1]+2;
    for(int i=3;i<=m;i++)
    {
        a[i]=a[i-1]+fib[i-2];
        a[i]%=mod;
    }
    cout<<a[m];
}
