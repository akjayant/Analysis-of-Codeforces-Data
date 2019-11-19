#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch>'9' || ch<'0'){
		if (ch=='-') w=-1;
		ch=getchar();
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
const int N=2005;
int n,m,tot;
ll a[N][N],d[N],ans;
int px[N],py[N],vis[N];
int c[N],w[N],pre[N];
int s[N],t[N],p[N];
int main(){
	n=read();
	for (int i=1;i<=n;++i)
		px[i]=read(),py[i]=read();
	for (int i=1;i<=n;++i) c[i]=read();
	for (int i=1;i<=n;++i) w[i]=read();
	for (int i=1;i<=n;++i){
		a[0][i]=a[i][0]=c[i];
		for (int j=1;j<=n;++j)
			a[i][j]=1ll*(w[i]+w[j])*(abs(px[i]-px[j])+abs(py[i]-py[j]));	
	}
	vis[0]=1;
	for (int i=1;i<=n;++i)
		d[i]=a[0][i],pre[i]=0;
	for (int cas=1;cas<=n;++cas){
		int mn=-1;
		for (int i=1;i<=n;++i)
			if (!vis[i] && (mn==-1 || d[mn]>d[i]))
				mn=i;
		if (!pre[mn]) p[++tot]=mn;
		else s[++m]=mn,t[m]=pre[mn];
		vis[mn]=1,ans+=d[mn];
		for (int i=1;i<=n;++i)
			if (!vis[i] && d[i]>a[mn][i])
				d[i]=a[mn][i],pre[i]=mn;
	}
	printf("%lld\n",ans);
	printf("%d\n",tot);
	for (int i=1;i<=tot;++i)
		printf("%d ",p[i]);
	puts("");
	printf("%d\n",m);
	for (int i=1;i<=m;++i)
		printf("%d %d\n",s[i],t[i]);
    return 0;
}
