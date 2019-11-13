//μ's forever
#include <bits/stdc++.h>
#define N 1005
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
int T,n,a[N],ans;
inline bool cmp(register int a,register int b)
{
    return a>b;
}
int main()
{
    T=read();
    while(T--)
    {
        n=read();
        for(register int i=1;i<=n;++i)
            a[i]=read();
        sort(a+1,a+1+n,cmp);
        ans=0;
        for(register int i=1;i<=n;++i)
            if(a[i]>=i)
                ans=i;
        write(ans),puts("");
    }
	return 0;
}
