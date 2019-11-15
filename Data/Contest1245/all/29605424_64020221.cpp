#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

char s[100005];
int f[100005];

int main ()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);

    gets(s+1);
    int n=strlen(s+1);

    f[0]=1;

    for(int i=1; i<=n; ++i)
    {
        f[i]=f[i-1];

        if(s[i]=='u'&&s[i-1]=='u')
            f[i]=(f[i]+f[i-2])%mod;

        if(s[i]=='n'&&s[i-1]=='n')
            f[i]=(f[i]+f[i-2])%mod;

        if(s[i]=='m'||s[i]=='w')
            f[i]=0;
    }

    printf("%d ",f[n]);
}
