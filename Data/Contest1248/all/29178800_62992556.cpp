#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long int power(long long int a,long long int b) {long long int ret=1;while(b) {if(b&1) ret*=a;a*=a;if(ret>=mod) ret%=mod;if(a>=mod) a%=mod;b>>=1;}return ret;}
long long int inv(long long int x) {return power(x,mod-2);}

int main()
{
    int n,m;
    cin>>n>>m;
    long long a[m+1];
    int i;
    a[1]=2;
    a[2]=4;
    long long b[n+1];
    b[1]=2;
    b[2]=4;
    for(i=3;i<=m;i++)
    {
        a[i]=(a[i-1]%mod+a[i-2]%mod)%mod;
    }
    for(i=3;i<=n;i++)
    {
        b[i]=(b[i-1]%mod+b[i-2]%mod)%mod;
    }
    if(n==1)
    {
        cout<<a[m]<<endl;
        return 0;
    }
    if(m==1)
    {
        cout<<b[n]<<endl;
        return 0;
    }
    long long p=1;
    for(i=1;i<=(n-1);i++)
    {
        p=(p%mod*2%mod)%mod;
    }
    long long p1=1;
    for(i=1;i<=(m-1);i++)
    {
        p1=(p1%mod*2%mod)%mod;
    }
    long long g=(b[n]%mod+p1%mod)%mod;
    g=(g%mod+(a[m]%mod+p%mod)%mod)%mod;

    p=(p%mod+p1%mod)%mod;
    p=(p%mod+2%mod)%mod;
    g=(g-p+mod)%mod;
    cout<<g<<endl;
}
