#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5,p=1e9+7;
char ch[N];
ll f[N];
int main()
{
    scanf("%s",ch+1);int n=strlen(ch+1);ll ans=1;
    f[2]=f[1]=1;for(int i=3;i<=n+3;i++)f[i]=(f[i-1]+f[i-2])%p;
    for(int i=1;i<=n;)
    {
        if(ch[i]=='m'||ch[i]=='w'){printf("0\n");return 0;}
        int j=i;while(j<=n&&ch[j]==ch[i])j++;
        if(ch[i]=='n'||ch[i]=='u')ans=ans*f[j-i+1]%p;
        i=j;
    }
    cout<<ans<<endl;
}
