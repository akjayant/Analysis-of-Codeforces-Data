//μ's forever
#include <bits/stdc++.h>
#define int long long
#define getchar nc
using namespace std;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
    register int x=0,f=1;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return x*f;
}
inline void write(register int x)
{
    if(!x)putchar('0');if(x<0)x=-x,putchar('-');
    static int sta[20];register int tot=0;
    while(x)sta[tot++]=x%10,x/=10;
    while(tot)putchar(sta[--tot]+48);
}
int n,m=0;
signed main()
{
    n=read();
    if(n==1)
    {
        puts("1");
        return 0;
    }
    for(m=2;m<=sqrt(n);++m)
        if(n%m==0)
            break;
    if(n%m!=0)
        m=n;
    while(n%m==0)
        n/=m;
    if(n!=1)
        puts("1");
    else
        write(m);
	return 0;
}
