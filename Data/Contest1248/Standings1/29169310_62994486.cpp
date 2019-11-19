#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define ha 1000000007
#define ui unsigned int
#define pii pair<int,int>
#define pid pair<int,double>

using namespace std;

inline int read()
{
    char ch=getchar(); int f=1,x=0;
    while (ch<'0' || ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
    while (ch>='0' && ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
    return f*x;
}

int n,m,f[100005];

signed main()
{
    n=read(); m=read();
    if (m>n) swap(n,m);
    f[1]=1,f[2]=2;
    for (int i=3;i<=n;i++) f[i]=(f[i-1]+f[i-2])%ha;
    return !printf("%d",(((f[n]+f[m]-1)%ha+ha)%ha)*2%ha);
}