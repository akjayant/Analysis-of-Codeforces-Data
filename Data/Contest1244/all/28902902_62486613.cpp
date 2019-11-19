#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,to[2][N],sz[N],c[3][N],x,y,q[N],g[5],d[5],s[N];
long long ans=1e18,rs;
void go(){
	int nw=0;
	for(int i=1;i<=n;++i){
		rs+=c[g[nw++]][q[i]];
		if(nw==3)nw=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int o=0;o<3;++o)for(int i=1;i<=n;++i)scanf("%d",&c[o][i]);
	for(int i=1;i<n;++i){
		scanf("%d %d",&x,&y);
		if(sz[x]==2||sz[y]==2){
			puts("-1");
			return 0;
		}
		to[sz[x]++][x]=y;
		to[sz[y]++][y]=x;
	}
	for(int i=1;i<=n;++i){
		if(sz[i]==1){
			q[1]=i;
			break;
		}
	}
	q[2]=to[0][q[1]];
	for(int i=3;i<=n;++i){
		if(to[0][q[i-1]]==q[i-2]){
			q[i]=to[1][q[i-1]];
		}else q[i]=to[0][q[i-1]];
	}
//	for(int i=1;i<=n;++i)printf("_%d ",q[i]);printf("\n");
	for(int i=1;i<=2;++i)g[i]=i;
	for(int i=1;i<=6;++i){
		rs=0;
		go();
		if(ans>rs){
			ans=rs;
			for(int o=0;o<=2;++o)d[o]=g[o];
		}
		next_permutation(g,g+3);
	}
	printf("%lld\n",ans);
	int nw=0;
	for(int i=1;i<=n;++i){
		s[q[i]]=1+d[nw++];
		if(nw==3)nw=0;
	}
	for(int i=1;i<=n;++i)printf("%d ",s[i]);
}
