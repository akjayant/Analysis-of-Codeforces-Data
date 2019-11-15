#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
char s[N];
int n;
ll f[N];
ll mod = 1e9+7;
int main()
{
    f[0]=f[1]=1;
    for(int i=2;i<N;i++)
    {
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    scanf("%s",s);
    n = strlen(s);
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='m'||s[i]=='w'){
            ans=0;break;}
        int j=i+1,t=1;
        while(j<n&&s[j]==s[j-1]&&(s[j]=='u'||s[j]=='n'))t++,j++;
        ans= ans*f[t]%mod;
        i=j-1;
    }
    printf("%lld\n",ans);
    return 0;
}
