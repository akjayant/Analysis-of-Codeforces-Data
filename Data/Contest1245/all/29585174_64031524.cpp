#include<cstdio>
inline void read(int &n)
{
	n=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		n=(n<<3)+(n<<1)+ch-'0';
		ch=getchar();
	}
	return;
}
typedef long long ll;
const int N=2000+10;
int ab(int x){return x<0?-x:x;}
int x[N],y[N],k[N],n,now,pre[N],len,a[N];
ll ans,f[N][N],dis[N],sum;
bool vis[N];
int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(x[i]),read(y[i]);
	for(int i=1;i<=n;i++)scanf("%lld",&dis[i]);
	for(int i=1;i<=n;i++)read(k[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			f[i][j]=f[j][i]=(ab(x[i]-x[j])+ab(y[i]-y[j]))*1ll*(k[i]+k[j]);
	for(int i=1;i<=n;i++)
	{
		sum=1e18;
		now=0;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]<sum)
			{
				sum=dis[j];
				now=j;
			}
		vis[now]=1;
		ans+=sum;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&dis[j]>f[now][j])
			{
				pre[j]=now;
				dis[j]=f[now][j];
			}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		if(!pre[i])a[++len]=i;
	printf("%d\n",len);
	for(int i=1;i<=len;i++)
		printf("%d ",a[i]);
	if(len)puts("");
	len=0;
	for(int i=1;i<=n;i++)
		if(pre[i])
		{
			x[++len]=pre[i];
			y[len]=i;
			if(x[len]>y[len])x[len]^=y[len]^=x[len]^=y[len];
		}
	printf("%d\n",len);
	for(int i=1;i<=len;i++)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}
