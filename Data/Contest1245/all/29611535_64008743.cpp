#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000
#define DIM 100007
#define pll pair<long long, long long>
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define mood 1000000007
#define y1 ghjhklkhkyj
#define pi 3.14159265358979323846
typedef  pair< long long, pair<long long, long long> > ppll;

long long  n,m,l,r,h,k,res1,a1,a2,w,a3,z,alln,a4,a5,a6,a7,a8,a9,a10,last,LL,timer,start,finish,flag,step,tests,kilk,curr,shift;
string s,s1,s2;
char t;
ll x,y;


ll dp[100007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    dp[0]=1;
    dp[1]=1;
    n=s.size();
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=mood;
    }
    t='*';
    a3=1;
    for(int i=0; i<n; i++)
    {
        if(s[i]==t&&t=='u')
        {
            a1++;
            a5=1;
        }
        else
        {
            if(s[i]==t&&t=='n')
            {
                a2++;
                a5=1;
            }
            else
            {
                if(t=='n')
                {
                    a3*=dp[a2];
                    a3%=mood;
                }
                else
                {
                    if(t=='u')
                    {
                        a3*=dp[a1];
                        a3%=mood;
                    }
                }
                a1=0;
                a2=0;
                if(s[i]=='n')a2++;
                if(s[i]=='u')a1++;
                if(s[i]=='m'||s[i]=='w'){
                    cout<<0<<endl;
                    return 0;
                }
                t=s[i];

            }
        }
    }
    if(t=='n')
    {
        a3*=dp[a2];
        a3%=mood;
        a5=1;

    }
    else
    {
        if(t=='u')

        {
            a3*=dp[a1];
            a3%=mood;
            a5=1;
        }
    }
    //if(a5==0)cout<<0<<endl;
    cout<<a3<<endl;
    return 0;
}
