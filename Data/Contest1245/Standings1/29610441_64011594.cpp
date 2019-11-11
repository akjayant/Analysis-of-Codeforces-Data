#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const int inf=INT_MAX;
const ll inff=1e18;
const ll mod=1e9+7;
#define pii pair<int,int>
#define mkp make_pair
#define F first
#define S second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define int ll

#ifdef HNO2
#define IOS
#else
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#endif // HNO2

string s;
int n;
int dp[maxn];

int32_t main()
{
    IOS
    dp[1]=1,dp[2]=2;
    for (int i=3;i<=150000;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
    cin>>s;
    s+="(";
    n=s.length();
    char last=s[0];
    int cnt=0;
    int ans=1;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='m'||s[i]=='w') return cout<<0<<endl,0;
        if (s[i]!=last)
        {
            if (last=='n') ans=(ans*dp[cnt])%mod;
            if (last=='u') ans=(ans*dp[cnt])%mod;
            last=s[i];
            cnt=0;
        }
        cnt++;
    }
    cout<<ans<<endl;
}

