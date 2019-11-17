using namespace std;

typedef long long ll;
const int maxn=1e6+7;
const ll mod=1e9+7;
string s;
ll n;
ll dp[maxn];

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    dp[1]=1,dp[2]=2;
    for (ll i=3;i<=150000;i++) dp[i]=(dp[i-1]+dp[i-2])%mod;
    cin>>s;
    s+="(";
    n=s.length();
    char last=s[0];
    ll cnt=0;
    ll ans=1;
    for (ll i=0;i<n;i++)
    {
        if (s[i]=='m'||s[i]=='w') return cout<<0<<'\n',0;
        if (s[i]!=last)
        {
            if (last=='n') ans=(ans*dp[cnt])%mod;
            if (last=='u') ans=(ans*dp[cnt])%mod;
            last=s[i];
            cnt=0;
        }
        cnt++;
    }
    cout<<ans<<'\n';
}
