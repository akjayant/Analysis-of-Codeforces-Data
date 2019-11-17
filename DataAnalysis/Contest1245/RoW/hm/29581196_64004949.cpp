using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize ("-O3")
using ll = long long;
const ll mod = 1000000007;





int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);




    string s;
    cin>>s;
    ll n=s.length();
    ll dp[n]={0};
    dp[0]=1;
    if(s[0]=='m' or s[0]=='w')
    {
        cout<<0<<endl;
        exit(0);
    }
    for (__typeof(n) a = (1) - ((1) > (n)); a != (n) - ((1) > (n)); a += 1 - 2 * ((1) > (n)))
    {
        if(s[a]=='m' or s[a]=='w')
        {
            cout<<0<<endl;
            exit(0);
        }
        dp[a]=dp[a-1];
        if(s[a]=='u' and s[a-1]=='u')
        {
            if(a>1)
                dp[a]=(dp[a]+dp[a-2])%mod;
            else
                dp[a]++;
        }
        if(s[a]=='n' and s[a-1]=='n')
        {
            if(a>1)
                dp[a]=(dp[a]+dp[a-2])%mod;
            else
                dp[a]++;
        }
    }
    cout<<dp[n-1]%mod<<endl;
 return 0;
}
