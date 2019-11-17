using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long LN = 21;

long long pw[LN],fact[N],invfact[N];

long long dp[N];

int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);;


    long long i,j;

    string s;
    cin>>s;

    long long n = s.length();
    dp[0] = 1;

    for(i=1;i<=s.length();i++)
    {
        if(s[i-1] == 'w' || s[i-1] == 'm')
        {
            cout<<"0\n";
            return 0;
        }
        dp[i] = dp[i-1];

        if(i >= 2 && ((s[i-1] == 'u' && s[i-2] == 'u') || (s[i-1] == 'n' && s[i-2] == 'n')))
        {
            dp[i] = (dp[i] + dp[i-2])%mod;
        }
    }
    cout<<dp[n];

    return 0;
}
