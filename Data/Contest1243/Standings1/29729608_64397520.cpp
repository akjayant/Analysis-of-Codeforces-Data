/*----Author:HenryHuang----*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int> d[maxn];
int fa[maxn];
int vis[maxn];
int cnt,st[maxn];
set<int> q;
set<int>::iterator it;
int getfa(int t){
	return fa[t]==t?fa[t]:fa[t]=getfa(fa[t]);
}
void merge(int x,int y){
	fa[getfa(x)]=getfa(y);
}
void bfs(int u){
    queue<int> Q;
    vector<int> ans;
    Q.push(u);
    vis[u]=1;
    int num=0;
    while(!Q.empty()){
        cnt=0;
        int u=Q.front();Q.pop();
        ans.push_back(u);
        ++num;
        for(it=q.begin();it!=q.end();++it){
        	if(d[u].empty()) vis[*it]=1,Q.push(*it),st[++cnt]=*it;
            else if(*lower_bound(d[u].begin(),d[u].end(),*it)!=(*it)&&(!vis[*it])){
				vis[*it]=1;
                Q.push(*it);
                st[++cnt]=*it;
            }
        }
        for(int i=1;i<=cnt;++i) q.erase(st[i]);
    }
    for(int i=1;i<ans.size();++i) merge(ans[i],ans[i-1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		int x,y;
		cin>>x>>y;
		d[x].emplace_back(y);
		d[y].emplace_back(x);
	}
	for(int i=1;i<=n;++i)
		q.insert(i),fa[i]=i;
	for(int i=1;i<=n;++i)
		sort(d[i].begin(),d[i].end());
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			bfs(i);
		}
	}
	int ans=0;
	for(int u=1;u<=n;++u){
		for(auto v:d[u]){
			if(getfa(u)!=getfa(v)){
				merge(u,v);
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

