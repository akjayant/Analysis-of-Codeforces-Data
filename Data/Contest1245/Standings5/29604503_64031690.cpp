#include <bits/stdc++.h>
using namespace std;
const int Nxc = 1e6;
inline char nc()
{
	static char buf[Nxc],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Nxc,stdin),p1==p2)?EOF:*p1++;
}
inline int read()
{
	int w=1,d=0; char ch=nc();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1; ch=nc();}
	while(ch>='0'&&ch<='9') d=(d<<3)+(d<<1)+(ch^48),ch=nc();
	return w*d;
}
const int N = 2010;
long long n,k[N],tot;
bool v[N];
struct Ver{
	int x,y;
}a[N];
struct Edge{
	int x,y;
	long long z;
	bool flag;
}edge[N*N];
int fa[N];
inline get_f(int x)
{
	return fa[x]==x? x : fa[x]=get_f(fa[x]);
}
bool cmp(Edge x,Edge y)
{
	return x.z<y.z;
}
long long ans;
int ff[N],fftot,fl[N][2],fltot;
int main()
{
	n=read();
	for(register int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	for(register int i=1;i<=n;i++) 
	{
		int x=read(); 
		edge[++tot]=(Edge){n+1,i,x,1};
	}
	for(register int i=1;i<=n;i++) k[i]=read();
	for(register int i=1;i<=n;i++)
	for(register int j=i+1;j<=n;j++) 
	{
		edge[++tot]=(Edge){i,j,(k[i]+k[j])*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)),0};
		edge[++tot]=(Edge){j,i,(k[i]+k[j])*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)),0};
	}
	sort(edge+1,edge+1+tot,cmp);
	n++;
	for(register int i=1;i<=n;i++) fa[i]=i;
	for(register int i=1;i<=tot;i++)
	{
		int x=get_f(edge[i].x),y=get_f(edge[i].y);
		if(x==y) continue;
		fa[x]=y;
		ans+=edge[i].z;
		if(edge[i].flag) ff[++fftot]=edge[i].y;
		else 
		{
			fltot++;
			fl[fltot][0]=edge[i].x,fl[fltot][1]=edge[i].y;
		}
	}
	cout<<ans<<endl;
	cout<<fftot<<endl;
	sort(ff+1,ff+1+fftot);
	for(register int i=1;i<=fftot;i++) cout<<ff[i]<<" "; cout<<endl;
	cout<<fltot<<endl;
	for(register int i=1;i<=fltot;i++)
	cout<<fl[i][0]<<" "<<fl[i][1]<<endl;
	return 0;
} 