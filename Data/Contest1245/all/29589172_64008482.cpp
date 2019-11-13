#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
const ll mod=1e9+7;

int f[N];char s[N];
void Init()
{
    f[1]=f[0]=1;
    for(int i=2;i<=100000;++i)f[i]=f[i-1]+f[i-2],f[i]%=mod;
    scanf("%s",s+1);
}
ll ans;

int main()
{
    Init();
    int n=strlen(s+1),cnt=1;
    ans=1;
    for(int i=1;i<=n;++i)
    {
        if((s[i]=='u'||s[i]=='n')&&s[i]==s[i-1])++cnt;
        else if(s[i]=='m'||s[i]=='w')ans=0;
        else ans=ans*f[cnt],ans%=mod,cnt=1;
    }
    ans=ans*f[cnt],ans%=mod;
    cout<<ans<<endl;
    return 0;
}
