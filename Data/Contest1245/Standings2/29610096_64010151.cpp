// by : 信冯哥
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5+5;
const int mod = (int)1e9+7;

typedef long double dl;
typedef long long ll;
//#define int ll

#define orz cout<<endl
#define debug cout<<"-------------------"<<endl
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define sync ios::sync_with_stdio(false)

int n,m,k,l,s,t,r,ans,T;
int dp[maxn][2];
int a[maxn];


int main()
{
	
    string p;
    cin>>p;
    n=p.length();
    for(auto i:p)
    {
        if(i=='m'||i=='w')
        {
            cout<<0<<endl;
            return 0;
        }
    }
    dp[1][0]=1;
    dp[1][1]=0;
    dp[0][0]=dp[0][1]=1;
    for(int i=2;i<=n;i++)
        dp[i][1]=dp[i-1][0],dp[i][0]=(dp[i-1][1]+dp[i-1][0])%mod;
    ll ans=1;
    a[1]=1;
    p.append("z");
    n++;
    for(int i=2;i<=n;i++)
    {

        if(p[i-2]!=p[i-1])
        {
            a[i]=1;
            if(p[i-2]=='u'||p[i-2]=='n')
                ans*=(ll)(dp[a[i-1]][0]+dp[a[i-1]][1])%mod,ans%=mod;
        }else a[i]=a[i-1]+1;
    }
    cout<<ans<<endl;

    return 0;
}

