#include<bits/stdc++.h>
#define ll long long
#define DEBUG
using namespace std;
const int maxn=300010;
const int mod=100007;
const int N = 500 + 7;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);

int n,m,cnt,ans,flag;

inline int read()
{
    register int c = getchar(), fg = 1, sum = 0;
    while(c > '9' || c < '0' )
    {
        if(c == '-')fg = -1;
        c = getchar();
    }
    while(c <= '9' && c >= '0')
    {
        sum = sum *10 + c - '0';
        c = getchar();
    }
    return fg * sum;
}
string str;
int dp[1010];
void init()
{
    n=read();
    cin>>str;
    for(int i=0;i<n;i++)dp[i]=0;
}

void go()
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]==49)
            ans=max(ans,max((i+1)*2,(n-i)*2));
    }
    for(int i=0;i<n;i++)
    {
        dp[i]=i?dp[i-1]+1:1;
        if(str[i]==49)
        {
            dp[i]++;
        }
        for(int j=i+1;j<n;j++)
        {
            if(str[j]==49)
            {
                ans=max(ans,dp[i]+(j-i)*2);
            }
        }
        ans=max(dp[i],ans);
    }
    for(int i=0;i<n;i++)dp[i]=0;
    for(int i=n-1;i>=0;i--)
    {
        dp[i]=(i<n-1?dp[i+1]+1:1);
        if(str[i]==49)
        {
            dp[i]++;
        }
        for(int j=i-1;j>=0;j--)
        {
            if(str[j]==49)
            {
                ans=max(ans,dp[i]+(i-j)*2);
            }
        }
        ans=max(dp[i],ans);
    }
    printf("%d\n",ans);
}
int main()
{
    int T=read();
    while(T--)
    {
        init();
        go();
    }
}
