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

char S[1004];

int main()
{
    int t=getnum();

    while(t--)
    {
        int n=getnum();
        gets(S+1);

        int ans=n;
        for(int i=1;i<=n;i++)if(S[i]=='1')ans++;
        for(int i=1;i<=n;i++)if(S[i]=='1')ans=max(ans,(n-i+1)*2);
        for(int i=n;i>=1;i--)if(S[i]=='1')ans=max(ans,i*2);

        printf("%d\n",ans);
    }
}