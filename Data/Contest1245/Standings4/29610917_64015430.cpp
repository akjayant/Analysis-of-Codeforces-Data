#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define Fi first
#define Se second
#define ll long long
#define inf 0x3f3f3f3f
#define lowbit(x) (x&-x)
#define ull unsigned long long
#define mmin(a,b,c) min(a,min(b,c))
#define mmax(a,b,c) max(a,max(b,c))
#define debug(a) cout<<#a<<"="<<a<<endl;
#define debug2(a,b) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<endl;
#define debug3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<endl;
#define show_time cout<<"The run time is:"<<(double)clock()/CLOCKS_PER_SEC<<"s"<<endl;
using namespace std;
const int N=3e5+10;
char s[N];
ll dp[N],fac[N];
const ll mod=1e9+7;
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            printf("%d\n",0);
            return 0;
        }
    }
    fac[1]=1;fac[2]=2;
    for(int i=3;i<=n;i++) {fac[i]=fac[i-1]+fac[i-2];fac[i]%=mod;}
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        if(s[j]=='u')
        {
            while(s[j]=='u') j++;
        }
        else if(s[j]=='n')
        {
            while(s[j]=='n') j++;
        }
        if(i==j) j++;
        ll len=j-i;
        ans*=fac[len];
        ans%=mod;
        i=j-1;
    }
    printf("%lld\n",ans);
    return 0;
}
/*

*/
