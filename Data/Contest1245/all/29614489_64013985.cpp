#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
#define N 2005
ll d[N][N],x[N],y[N],k[N],f[N],tt;
int n,v1,v2,pr[N];
bool vis[N],vis2[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
	for(int i=1;i<=n;++i)
		cin>>d[0][i],d[i][0]=d[0][i];
	for(int i=1;i<=n;++i) cin>>k[i];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			if(i!=j) d[i][j]=(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
			else d[i][j]=1e15;
		}
	memset(f,63,sizeof(f)); f[0]=0;
	for(int i=0;i<=n;++i){
		int x=n+1;
		for(int j=0;j<=n;++j) if(!vis[j]&&f[j]<f[x]) x=j;
		if(x>0){
			if(pr[x]==0) ++v1;
			else ++v2;
		}vis[x]=1; tt+=f[x];
		for(int j=0;j<=n;++j)
			if(!vis[j]&&f[j]>d[x][j]){
				f[j]=d[x][j];
				pr[j]=x;
			}
	}
	cout<<tt<<endl<<v1<<endl;
	for(int i=1;i<=n;++i) if(!pr[i]) printf("%d ",i);
	printf("\n%d\n",v2);
	for(int i=1;i<=n;++i) if(pr[i]) printf("%d %d\n",i,pr[i]);
	return 0;
}

