//μ's forever
#include <bits/stdc++.h>
#define int long long
#define N 2005
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
int n,px[N],py[N],c[N],k[N];
int c1[N],c2[N],P[N],f[N];
int ans;
vector<int> v1;
vector<pair<int,int> >v2;
signed main()
{
    n=read();
    for(register int i=1;i<=n;++i)
        px[i]=read(),py[i]=read();
    for(register int i=1;i<=n;++i)
        c[i]=read(),c1[i]=c[i],c2[i]=1e18;
    for(register int i=1;i<=n;++i)
        k[i]=read();
    for(register int i=1;i<=n;++i)
    {
        int minn=1e18,pos=0;
        for(register int j=1;j<=n;++j)
            if(!f[j]&&minn>min(c1[j],c2[j]))
                minn=min(c1[j],c2[j]),pos=j;
        if(!pos)
            break;
        //write(pos);
        f[pos]=1,ans+=minn;
        if(c1[pos]<c2[pos])
            v1.push_back(pos);
        else
            v2.push_back(make_pair(pos,P[pos]));
        for(register int j=1;j<=n;++j)
            if(!f[j])
            {
                int val=(fabs(px[j]-px[pos])+fabs(py[j]-py[pos]))*(k[j]+k[pos]);
                if(val<c2[j])
                    c2[j]=val,P[j]=pos;
            }
    }
    write(ans),puts("");
    write(v1.size()),puts("");
    for(register int i=0;i<v1.size();++i)
        write(v1[i]),putchar(' ');
    puts("");
    write(v2.size()),puts("");
    for(register int i=0;i<v2.size();++i)
        write(v2[i].first),putchar(' '),write(v2[i].second),puts("");
	return 0;
}
