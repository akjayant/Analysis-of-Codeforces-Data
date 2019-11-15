#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
#define ll long long
#define mod 1000000007
#define maxx 100005
using namespace std;
char s[maxx];
int f[maxx];
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
                if(f[i]>=mod)f[i]-=mod;
            }
        }
    }
    cout<<f[n]<<endl;
    return 0;
}