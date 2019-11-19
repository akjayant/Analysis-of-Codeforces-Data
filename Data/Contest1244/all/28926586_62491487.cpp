#include<bits/stdc++.h>
#define N (100005)
#define ll long long
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define bitdebug(x) cerr<<bitset<8>(x)<<endl
#define CM cerr<<(&MOP2-&MOP1)/1024.0/1024.0<<endl
using namespace std;
template <class T> T Min(T x,T y) {
	return x<y?x:y;
}
template <class T> T Max(T x,T y) {
	return x>y?x:y;
}
bool MOP1;
int n,cnt[N];
ll col[N][3];
int to[N][5];
int s;
int A[N],B[N];
ll res,ans=1e14+5;
void dfs(int x,int fa,int a,int b) {
	for(int i=1; i<=2; i++) {
		int y=to[x][i];
		if(y==fa)continue;
		res+=col[y][a^b];
		A[y]=a^b;
		dfs(y,x,b,a^b);
	}
}
bool MOP2;
int main() {
	scanf("%d",&n);
	for(int j=1; j<=3; j++)for(int i=1; i<=n; i++)scanf("%lld",&col[i][j]);
	for(int i=1; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		cnt[x]++,cnt[y]++;
		if(cnt[x]>2||cnt[y]>2) {
			puts("-1");
			return 0;
		}
		to[x][cnt[x]]=y,to[y][cnt[y]]=x;
	}
	for(int i=1; i<=n; i++) {
		if(cnt[i]==1) {
			s=i;
			break;
		}
	}
	int b=to[s][1];
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			if(i^j) {
				A[s]=i,A[b]=j;
				res=col[s][i]+col[b][j];
				dfs(b,s,i,j);
				if(res<ans)memcpy(B,A,sizeof B),ans=res;
			}
		}
	}
	printf("%lld\n",ans);
	for(int i=1; i<=n; i++)printf("%d ",B[i]);
	return 0;
}

