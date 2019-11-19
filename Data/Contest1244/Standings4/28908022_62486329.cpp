#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scan(x) scanf("%d",&x)
const int maxn = 1e5+10;
const ll inf=1e18+10;
vector<int> adj[maxn];
int color[4][maxn];
int f[maxn];
int main() {
 	int n;
 	scan(n);
 	for(int i=1;i<=3;i++){
 		for(int j=1;j<=n;j++){
 			scan(color[i][j]);
		 }
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		scan(u),scan(v);
		adj[u].push_back(v);
		adj[v].push_back(u); 
	}
	int start;
	for(int i=1;i<=n;i++){
		if(adj[i].size()>2){
			cout<<-1<<endl;
			return 0;
		}
		if(adj[i].size()==1){
			start=i;
		}
	}
	int a[3]={1,2,3};
	ll maxx=inf;
	do{
		int cnt=1;
		ll res=color[a[0]][start];
		int next=adj[start][0];
		int parent=start;
		while(adj[next].size()!=1){
			res+=color[a[cnt%3]][next];
			cnt++;
			for(int i=0;i<2;i++){
				if(adj[next][i]==parent)continue;
				parent=next;
				next=adj[next][i];
				break;
			}
		}
		res+=color[a[cnt%3]][next];
		if(res<maxx){
			maxx=res;
			f[start]=a[0];
			int cnt=1;
			int next=adj[start][0];
			int parent=start;
			while(adj[next].size()!=1){
			f[next]=a[cnt%3];
			cnt++;
			for(int i=0;i<2;i++){
				if(adj[next][i]==parent)continue;
				parent=next;
				next=adj[next][i];
				break;
			}
			}
			f[next]=a[cnt%3];
		}
	}while(next_permutation(a,a+3));
	cout<<maxx<<endl;
	for(int i=1;i<=n;i++)cout<<f[i]<<" ";
	cout<<endl;
    return 0;
}
