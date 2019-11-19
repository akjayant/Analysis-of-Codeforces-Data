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

int main()
{
    int t=getnum();

    while(t--)
    {
        int a=getnum(),b=getnum(),c=getnum(),d=getnum(),k=getnum();

        a=(a/c+(a%c>0));
        b=(b/d+(b%d>0));

        if(a+b>k)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d\n",a,b);
        }
        
    }
}