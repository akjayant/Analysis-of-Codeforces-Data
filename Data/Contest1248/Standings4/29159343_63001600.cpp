#include<bits/stdc++.h>
const int  mod=1e9+7;
const int N = 1e5+7;
const int inf= 0x3f3f3f3f;
typedef long long ll;
using namespace std;
ll f[N][10];

int main()
{

    ll n,m;

    f[1][0]=1;
    f[1][1]=1;
    f[2][0]=1;
    f[2][3]=1;
    f[2][1]=1;
    f[2][2]=1;
    for(int i=3;i<=100000;i++)
    {
        f[i][0]=f[i-1][2]%mod;
        f[i][1]=(f[i-1][0]+f[i-1][2])%mod;
        f[i][2]=(f[i-1][1]+f[i-1][3])%mod;
        f[i][3]=f[i-1][1]%mod;
    }
  while(cin>>n>>m){
    ll ans=0;
    ll sum=0;
    for(int i=0;i<4;i++)
        {
        //cout<<f[m][i]<<' ';cout<<endl;
        sum+=f[m][i];
        ans+=f[n][i];
        }
       // cout<<sum<<' '<<ans<<endl;
    ans+=sum-2;
    cout<<ans%mod<<endl;
  }
}
/*
3 3
1 2 1 1
2 3 2 1
1 3 1 1
*/
