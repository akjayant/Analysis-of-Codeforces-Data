#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int n,m,ans,fa[N];
vector<int> s[N];
bool vis[110000];

int findpa(int x) {
	if(fa[x]!=x) fa[x]=findpa(fa[x]);
	return fa[x];
}

void dfs(int x) {
	vis[x]=1,fa[x]=x+1;
	int mmax=0;
	for(int y=findpa(1);y<=n;y=findpa(y+1)) {
		while(mmax<s[x].size() && s[x][mmax]<y) mmax++;
		if(mmax<s[x].size() && s[x][mmax]==y) continue;
		dfs(y);
	}
}

int main() {
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++) {
		scanf("%d %d",&x,&y);
		s[x].push_back(y),s[y].push_back(x);
	} 
	for(int i=1;i<=n;i++) sort(s[i].begin(),s[i].end());
	for(int i=1;i<=n+1;i++) fa[i] = i;
	for(int i=1;i<=n;i++) if(!vis[i]) ans++, dfs(i);
	printf("%d\n",ans-1);
	return 0;
}