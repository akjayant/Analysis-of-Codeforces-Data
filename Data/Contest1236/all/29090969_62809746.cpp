#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=100003;

int n,m,k,u,d,l,r,dir,x,y,cnt;
ll sum;
int dx[5]={0,0,1,0,-1};
int dy[5]={0,1,0,-1,0};
vector<int> C[maxn],R[maxn];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	dir=1;r=m+1;d=n+1;x=y=sum=u=1;int t;
	for(int i=1;i<=k;++i){
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		R[xx].push_back(yy);
		C[yy].push_back(xx);
	}
	for(int i=1;i<=n;++i)sort(R[i].begin(),R[i].end());
	for(int i=1;i<=m;++i)sort(C[i].begin(),C[i].end());
	while(true){
//		printf("%d %d %d %d %d %d !\n",x,y,u,d,l,r);
		if(dir&1){
			int k=lower_bound(R[x].begin(),R[x].end(),y)-R[x].begin();
			if(dir==1){
				if(k==R[x].size())t=r-1;
				else t=min(r-1,R[x][k]-1);
				r=t;
			}else{
				if(k==0)t=l+1;
				else t=max(l+1,R[x][--k]+1);
				l=t;
			}
			if(++cnt>2)break;
			sum+=abs(t-y);
			if(y!=t)cnt=1;
			y=t;
		}else{
			int k=lower_bound(C[y].begin(),C[y].end(),x)-C[y].begin();
			if(dir==2){
				if(k==C[y].size())t=d-1;
				else t=min(d-1,C[y][k]-1);
				d=t;
			}else{
				if(k==0)t=u+1;
				else t=max(u+1,C[y][--k]+1);
				u=t;
			}
			if(++cnt>2)break;
			sum+=abs(t-x);
			if(x!=t)cnt=1;
			x=t;
		}
		++dir;
		if(dir==5)dir=1;
	}
//	printf("%d !\n",sum);
	puts(1ll*n*m-k==sum?"Yes":"No");
	return 0;
}
