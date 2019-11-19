//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//const int N=1e7+10;
//int n,m;
//int g[10][10];
//int dir[4][2]={0,1,1,0,0,-1,-1,0};
//int sum=0;
//bool judge()
//{
//    bool ok=true;
//    for(int i=1;i<=n;++i)
//    {
//        for(int j=1;j<=m;++j)
//        {
//            int cnt=0;
//            for(int k=0;k<4;++k)
//            {
//                int xx=i+dir[k][0];
//                int yy=j+dir[k][1];
//                if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
//                {
//                    if(g[xx][yy]==g[i][j])
//                        cnt++;
//                }
//            }
//            if(cnt > 1)
//                return false;
//        }
//    }
//    return true;
//
//}
//void dfs(int k)
//{
//    if(k>n*m)
//    {
//        if(judge())
//        {
//            sum++;
//        }
//        return ;
//    }
//    int x=(k+m-1)/m;
//    int y=k%m;
//    if(y==0) y=m;
//    g[x][y]=0;
//    if(!(x>1&&y>1&&g[x-1][y]==g[x][y]&&g[x][y-1]==g[x][y]))
//        dfs(k+1);
//    g[x][y]=1;
//    if(!(x>1&&y>1&&g[x-1][y]==g[x][y]&&g[x][y-1]==g[x][y]))
//        dfs(k+1);
//    return ;
//}
//int main()
//{
//    sum=0;
//    for(int i=1;i<=1;++i)
//    {
//        for(int j=1;j<=7;++j)
//        {
//            if( j < i)
//            {
//                 printf("   ");
//                 continue;
//            }
//            sum=0;
//            n=i;
//            m=j;
//            dfs(1);
//            printf("%2d ",sum);
//        }
//        cout<<endl;
//    }
//    while(cin>>n>>m)
//    {
//        sum=0;
//        dfs(1);
//        cout<<sum<<endl;
//    }
//}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
const ll mod=1e9+7;
ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
ll d[N];
ll f[N];
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        if(n>m)
            swap(n,m);
        ll ans=0;
        f[0]=2;
        f[1]=2;
        for(int i=2; i<=m; ++i)
            f[i]=(f[i-1]+f[i-2])%mod;
        ans=f[m];
        d[0]=0;
        d[1]=2;
//        cout<<" ans:"<<ans<<endl;
        f[1]=ans;
        for(int i=2; i<=n; ++i)
        {
            f[i]=(f[i-1]+d[i-1])%mod;;
            d[i]=(d[i-1]+d[i-2])%mod;
//            cout<<" i:"<<i<<" :"<<f[i]<<endl;
        }
        cout<<f[n]<<endl;
    }

}
