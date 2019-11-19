#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+6;
ll mod=1e9+7;
ll inv[N],fac[N];


ll C(int n,int m)
{   
    if(m==0)return 1;
    if(n<m||m==0)return 0;
    return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main()
{   
    int n,m;
    cin>>n>>m;
    inv[0]=inv[1]=fac[1]=1;
    for(int i=2;i<=N;i++)fac[i]=fac[i-1]*i%mod;
    for(int i=2;i<=N;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i=2;i<=N;i++)inv[i]=inv[i-1]*inv[i]%mod;
  
    /*
    for(int i=1;i<=100;i++)f[i][1]=i-1;
    f[1][1]=f[1][1]=0;
    
    for(int i=2;i<=300;i++)//选几个
    {
        for(int j=1;j<=300;j++)
        for(int k=1;k<=j-2;k++)
        f[j][i]+=f[k][i-1];
    }

    for(int i=1;i<=20;i++)
    {   
        printf("i=%d ",i);
        for(int j=1;j<=10;j++)
        printf("%lld ",f[i][j]);
        cout<<endl;
    }
    cout<<endl<<endl<<endl;
    for(int i=1;i<=20;i++)
    {
        
        for(int j=1;j<=20;j++)
        printf("%lld ",C(i,j) );
        cout<<endl;
    }
    */
    
    ll ans=1;

    for(int i=1;i<=n;i++)
    {
        if(i*2>n)break;
        //printf("n-i=%d i-1=%d\n",n-i,i-1);
        ans=(ans+C(n-i,i) )%mod;
    }
    for(int i=1;i<=m;i++)
    {
        if(i*2>m)break;
        ans=(ans+C(m-i,i) )%mod;
    }

  
    cout<<ans*2%mod;

    return 0;
}