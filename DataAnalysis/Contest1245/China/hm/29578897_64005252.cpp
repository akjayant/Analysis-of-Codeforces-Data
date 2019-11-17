using namespace std;
typedef long long ll;
const int MAXN=300050;
const int MOD=1e9+7;


int a[MAXN];
char s[MAXN];

int main()
{
    a[1]=a[0]=1;
    for(int i=2;i<=1e5;i++)(a[i]=a[i-1]+a[i-2])%=MOD;
    scanf("%s",s+1);
    int sz=strlen(s+1);
    int cnt=1;
    ll ans=1;
    for(int i=1;i<=sz;i++)
    {
        if((s[i]=='u'||s[i]=='n')&&s[i]==s[i-1])
        {
            cnt++;
        }
        else if(s[i]=='m'||s[i]=='w')ans=0;
        else
        {
            (ans*=a[cnt])%=MOD;
            cnt=1;
        }
    }
    (ans*=a[cnt])%=MOD;
    cout<<ans;
    return 0;
}
