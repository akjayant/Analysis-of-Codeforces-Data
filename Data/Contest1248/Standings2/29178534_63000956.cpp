#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define endl '\n'
const int mod=1e9+7;
int dp[300000][3][2];
int f(int i,int last,int ch,int end)
{
    if(i==end)
        return 1;
    int &ans=dp[i][last][ch];
    if(ans!=-1)
        return ans;
    if(ch==0)
    {
        ans=f(i+1,0,(last==0),end)+f(i+1,1,(last==1),end);
        ans%=mod;
        return ans;
    }
    ans=f(i+1,(last^1),0,end);
    return ans;
}
int32_t main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    int ans2=f(0,2,0,m)-2;
    memset(dp,-1,sizeof(dp));
    int ans1=f(0,2,0,n)-2;
    cout<<(ans1+ans2+2)%mod;
}
    
    