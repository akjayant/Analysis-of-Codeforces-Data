#include<bits/stdc++.h>
//#define DEBUG
#define FOR(i,n) for(int i=1;i<=n;i++)
#define FORZ(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 32622
#define MOD 1000000007  
#define LD long long double
#define bpc __builtin_popcount
#define gentum getnum
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

vector<int> V[100004],W;
ll A[100004][3],Ans[100004];
ll dp[100004][3][3];

void dfs(int n,int p)
{
    W.pb(n);
    for(int i=0;i<V[n].size();i++)
    {
        if(V[n][i]!=p)
        {
            dfs(V[n][i],n);
        }
    }
}

int main()
{
    ll n=getnum();

    for(int j=0;j<3;j++)for(int i=1;i<=n;i++)A[i][j]=getnum();

    for(int i=1;i<n;i++)
    {
        int x=gentum(),y=getnum();
        V[x].pb(y);
        V[y].pb(x);

        if(V[x].size()==3||V[y].size()==3)
        {
            printf("-1");
            return 0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(V[i].size()==1)
        {
            dfs(i,0);
            break;
        }
    }

    for(int i=0;i<W.size();i++)
    {
        int x=W[i];
        
        if(i==0)
        {
            dp[x][1][2]=A[x][2];
            dp[x][0][2]=A[x][2];
            dp[x][2][1]=A[x][1];
            dp[x][0][1]=A[x][1];
            dp[x][1][0]=A[x][0];
            dp[x][2][0]=A[x][0];
        }
        else
        {
            int y=W[i-1];
            dp[x][1][2]=A[x][2]+dp[y][0][1];
            dp[x][0][2]=A[x][2]+dp[y][1][0];
            dp[x][2][1]=A[x][1]+dp[y][0][2];
            dp[x][0][1]=A[x][1]+dp[y][2][0];
            dp[x][1][0]=A[x][0]+dp[y][2][1];
            dp[x][2][0]=A[x][0]+dp[y][1][2];
        }
    }

    int x=W.back();

    int ii=0,jj=1;

    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    {
        if(i==j)continue;
        if(dp[x][ii][jj]>dp[x][i][j])ii=i,jj=j;
    }

    ll ans=dp[x][ii][jj];

    for(int i=W.size()-1,cur=jj;i>=0;i--)
    {
        Ans[W[i]]=cur+1;
        if(cur==jj)cur=ii;
        else if(cur==ii)cur=3-ii-jj;
        else cur=jj;
    }

    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)printf("%lld ",Ans[i]);
}