#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
inline int read(){
	register int res=0, c;
	while(c=getchar(), c<'0'||c>'9');
	do{
		res=(res*10)+(c^48);
	} while(c=getchar(), c>='0'&&c<='9');
	return res;
}
int c[3][100010];
vector<int> edge[100010];
int vis[100010], to[100010], fan[100010];
void dfs(int x){
	vis[x]=1;
	for(auto i:edge[x])if(!vis[i]){
		to[x]=i;
		dfs(i);
	}
}
int main() {
	int n=read();
	for(int i=0; i<3; i++)for(int j=1; j<=n; j++)c[i][j]=read();
	for(int i=1; i<n; i++){
		int a=read() , b=read();
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		if(edge[i].size()>=3)return puts("-1"), 0;
	}
	int start;
	for(int i=1; i<=n; i++){
		if(edge[i].size()==1){
			start=i; dfs(i); break;
		}
	}
	int second = to[start];
	long long ans = 0x3f3f3f33f3f3f3f;
	for(int i=0; i<=2; i++)
		for(int j=0; j<=2; j++)if(i!=j){
			int ppre = i, pre = j, now = 3-i-j, tmp;
			long long res = c[i][start]+c[j][second];
			for(int k=2, ka=to[second]; k<n; k++, ka=to[ka]){
				res += c[now][ka];
				tmp = ppre;
				ppre = pre;
				pre = now;
				now = tmp;
			}
			if(ans>res){
				ans = res;
				fan[start]=i;
				fan[second]=j;
				ppre = i, pre = j, now = 3-i-j;
				for(int k=2, ka=to[second]; k<n; k++, ka=to[ka]){
					fan[ka]=now;
					tmp = ppre;
					ppre = pre;
					pre = now;
					now = tmp;
				}
			}
		}
	cout<<ans<<endl;
	for(int i=1; i<=n; i++)printf("%d ", fan[i]+1);
	return 0;
}

/*
1000000000000 66667 100000 33333
*/