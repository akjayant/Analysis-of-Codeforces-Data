#include<bits/stdc++.h>
#define maxn 100005
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define plll pair<pll,pll>
#define mod 1000000007
using namespace std;


/*ll digni(ll x,ll y)
{
    if(y==0)return 1;
    if(y%2==0)
    {
        ll res=digni(x,y/2);
        return (res*res)%mod;
    }
    return (digni(x,y-1)*x)%mod;
}*/

int n;
ll dp[maxn];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>s;
    int n=s.size();

    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }

    ll sol=1;
    int i=0;
    while(i<n)
    {
        if(s[i]=='u')
        {
            int tre=0;
            while(i<n && s[i]=='u')
            {
                tre++;
                i++;
            }

            sol*=dp[tre];
            sol%=mod;
        }
        else if(s[i]=='n')
        {
            int tre=0;
            while(i<n && s[i]=='n')
            {
                tre++;
                i++;
            }

            sol*=dp[tre];
            sol%=mod;
        }
        else if(s[i]=='m' || s[i]=='w')
        {
            cout<<"0\n";
            return 0;
        }
        else
        {
            i++;
        }
    }

    cout<<sol<<"\n";


    return 0;
}
