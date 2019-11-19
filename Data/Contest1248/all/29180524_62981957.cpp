#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<set>
#include<queue>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dwn(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
int n,a[100010],sum1=0,sum2=0;
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
    n=read();
    rep(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    rep(i,1,n/2) sum1+=a[i];
    rep(i,n/2+1,n) sum2+=a[i];
    printf("%I64d\n",(ll)sum1*sum1+(ll)sum2*sum2);
    return 0;
}
