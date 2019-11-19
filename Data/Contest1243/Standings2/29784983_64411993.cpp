#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
map<int,int>mp[maxn];
int hd,nxt[maxn];
void bfs(){
	int now,pre;
	queue<int>q;
	q.push(hd),hd=nxt[hd];
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(now=hd,pre=0;now;now=nxt[now]){
			if(!mp[v][now]){
				q.push(now);
				if(hd==now) hd=nxt[hd];
				nxt[pre]=nxt[now];
			}
			else{
				pre=now;
			}
		}
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		mp[u][v]=1,mp[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		nxt[i]=hd;
		hd=i;
	}
	int ans=0;
	while(hd){
		bfs();
		ans++;
	}
	printf("%d\n",ans-1);
}