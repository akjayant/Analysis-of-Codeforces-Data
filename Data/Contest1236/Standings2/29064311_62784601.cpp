//μ's forever
#include <bits/stdc++.h>
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
int T,a,b,c,ans;
int main()
{
    T=read();
    while(T--)
    {
        a=read(),b=read(),c=read(),ans=0;
        for(register int i=0;i<=100;++i)
            for(register int j=0;j<=100;++j)
                if(i<=a&&i*2+j<=b&&j*2<=c)
                    ans=max(ans,(i+j)*3);
        write(ans),puts("");
    }
	return 0;
}
