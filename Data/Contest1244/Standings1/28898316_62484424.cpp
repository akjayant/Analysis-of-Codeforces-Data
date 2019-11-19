#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define LL long long 
typedef long long ll;
const int N=5e5+5;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
typedef pair<int,int> pii;
int n;
ll c[3][N];
ll f[3][N];int g[3][N];
int in[N],b[N],col[N],cool[N];
vector<int> G[N];
int _get(int x,int y){
	if(x>y) swap(x,y);
	if(x==0) {
		if(y==1) return 2;
		return 1;
	} 
	return 0;
}
int main(){
	n=read();
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++)
			c[i][j]=read(),f[i][j]=1e18;
	} 
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		G[a].push_back(b);
		G[b].push_back(a);
		in[a]++;in[b]++;
		if(in[a]>2||in[b]>2) {puts("-1");return 0;}
	}
	int s=0;
	for(int i=1;i<=n;i++) if(in[i]==1) s=i;
	int num=1;b[num]=s;int fa=0;
	while(1){
		for(int v:G[s]) {
			if(v==fa) continue;
			b[++num]=v;
			fa=s;s=v;
			break;
		}
		if(num==n) break;
	}
	ll ans=1e18;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			if(i==j) continue;
			ll res=(c[i][b[1]]+c[j][b[2]]);
			col[b[1]]=i,col[b[2]]=j;
			for(int k=3;k<=n;k++){
				int t=_get(col[b[k-1]],col[b[k-2]]);
				col[b[k]]=t;
				res+=c[t][b[k]];
			}
			if(res<ans){
				ans=res;
				for(int k=1;k<=n;k++) cool[k]=col[k];
			}
		} 
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) printf("%d ",cool[i]+1);
	return 0;
} 