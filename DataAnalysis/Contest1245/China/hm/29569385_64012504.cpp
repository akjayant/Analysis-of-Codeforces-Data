using namespace std;
typedef long long ll;
const int maxn=2e5+10;

ll mod=1e9+7;
ll qpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)
            ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
char s[maxn];
ll dp[maxn];
int main()
{
    scanf("%s",s);
    int len=strlen(s);
    ll ans=1;
    int cnt=0;
    ll u=0,n=0;
    dp[1]=1;
    dp[2]=2;
    int no=1;
    for(int i=3;i<=len;i++)
    {
        dp[i]=(dp[i-2]+dp[i-1])%mod;
    }
    for(int i=0;i<len;i++)
    {
        if(s[i]=='w'||s[i]=='m')
        {
            printf("0\n");
            return 0;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(s[i]=='u')
            u++;
        else
        {
            if(u>=1)
                ans=ans*dp[u]%mod;
            u=0;
        }

    }
    if(u>=1)
        ans=ans*dp[u]%mod;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='n')
            n++;
        else
        {
            if(n>=1)
            ans=(ans*dp[n])%mod;
            n=0;
        }

    }
    if(n>=1)
        ans=(ans*dp[n])%mod;
    printf("%lld\n",ans%mod);
    return 0;
}
