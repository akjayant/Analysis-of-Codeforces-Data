using namespace std;
char s[100005];
int f[100005];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0<<endl;
            return 0;
        }
    }
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1];
        if(s[i]=='n'||s[i]=='u')
        {
            if(s[i]==s[i-1])
            {
                f[i]+=f[i-2];
                if(f[i]>=1000000007)f[i]-=1000000007;
            }
        }
    }
    cout<<f[n]<<endl;
    return 0;
}
