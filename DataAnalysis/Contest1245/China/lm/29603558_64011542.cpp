using namespace std;
typedef long long ll;
const int mod=1000000007;
int n,tmp=0,a[100010];
char now='a',s[100010];
ll ans=1;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    a[1]=1,a[2]=2;
    for(int i=(3);i<=(n);++i) a[i]=(a[i-1]+a[i-2])%mod;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='w'||s[i]=='m')
        {
            printf("0\n");return 0;
        }
        if(now==s[i]) ++tmp;
        else
        {
            if(now=='u'||now=='n')
            {
                ans=ans*a[tmp]%mod;
            }
            now=s[i],tmp=1;
        }
    }
    if(now=='u'||now=='n')
    {
        ans=ans*a[tmp]%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}
