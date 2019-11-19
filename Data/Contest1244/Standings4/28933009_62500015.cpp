#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,num=1;
int c[5][100010];
struct node{
	int to;
	int next;
}road[200010];
int head[100010],in[100010];
int top=0; 
int a[100010],cnt=0;
long long f[100010][4][4];//填了i个点，当前点填j，前面一个点填了k，最小花费 
int pre[100010][4][4];
int ans[100010];
void build(int from,int to){
	road[++num].next=head[from];
	road[num].to=to;
	head[from]=num;
}
void dfs(int x,int fa){
	a[++cnt]=x;
	for(int i=head[x];i;i=road[i].next){
		int y=road[i].to;
		if(y==fa)continue;
		dfs(y,x);
	}
}
int main(){
	memset(f,0x3f,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[1][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[2][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[3][i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		build(u,v);
		build(v,u);
		in[v]++;
		in[u]++;
	}
	for(int i=1;i<=n;i++){
		if(in[i]>2){
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(in[i]==1){
			top=i;
			break;
		}
	}
	dfs(top,top);
	f[1][1][1]=f[1][1][2]=f[1][1][3]=c[1][a[1]];
	f[1][2][1]=f[1][2][2]=f[1][2][3]=c[2][a[1]];
	f[1][3][1]=f[1][3][2]=f[1][3][3]=c[3][a[1]];
	for(int i=2;i<=n;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++){
				for(int t=1;t<=3;t++){
					if(j==k||k==t||j==t)continue;
					if(f[i-1][k][t]+c[j][a[i]]<f[i][j][k]){ 
						f[i][j][k]=f[i-1][k][t]+c[j][a[i]];
					//	cout<<f[i-1][k][t]<<" "<<c[j][a[i]]<<endl;
						pre[i][j][k]=t;
					//	cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<" "<<pre[i][j][k]<<endl;
					}
				}
			//	if(j!=k)cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
			}
		}
	}
	long long minn=1e18;
	int ans1=0,ans2=0;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			if(f[n][i][j]<minn){
				minn=f[n][i][j];
			//	cout<<"#"<<i<<" "<<j<<endl;
				ans1=i;
				ans2=j;
			} 
		}
	}
	if(minn==1e18){
		printf("-1\n");
		return 0;
	}
	cout<<minn<<endl;
	int now=n-1;
	ans[a[n]]=ans1;
	while(now){
		ans[a[now]]=ans2;
		int t=ans2;
		int ans3;
		for(ans3=1;ans3<=3;ans3++){
			if(ans3==ans1||ans3==ans2)continue;
			break;
		}
		ans2=ans3;
		ans1=t;
		now--;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}