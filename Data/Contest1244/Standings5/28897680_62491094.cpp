#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
vector<int>g[100005];
int a[4][100005];
int indx[100005];
void dfs(int node,int idx,int parent){
	indx[idx]=node;
	for(int to:g[node]){
		if(to!=parent){
			dfs(to,idx+1,node);
		}
	}
}
int find(int one,int second){
	if(one!=1 and second!=1){
		int o=1;
		return o;
	}
	if(one!=2 and second!=2){
		int o=2;
		return o;
	}
	if(one!=3 and second!=3){
		int o=3;
		return o;
	}
}
int32_t main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[1][i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[2][i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[3][i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int flag=0;
	int v=0;
	for(int i=1;i<=n;i++){
		if(g[i].size()>2){
			cout<<"-1"<<endl;
			return 0;
		}
		if(g[i].size()==1 and v==0){
			v=i;
		}
	}
	dfs(v,1,-1);
	int first=1;
	int second=2;
	int cost=100000000000000;
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i!=j){
				int tempCost=0;
				int first_node=indx[1];
				int second_node=indx[2];
				int first_color=i;
				int second_color=j;
				tempCost=a[first_color][first_node]+a[second_color][second_node];
				for(int it=3;it<=n;it++){
					int cur=indx[it];
					int current_color=find(first_color,second_color);
					tempCost+=a[current_color][cur];
					first_color=second_color;
					second_color=current_color;
				}
				if(tempCost<cost){
					first=i;
					second=j;
					cost=tempCost;
				}
			}
		}
	}
	int ans[n+1];
	ans[indx[1]]=first;
	ans[indx[2]]=second;
	for(int i=3;i<=n;i++){
		int cur=indx[i];
		ans[cur]=find(first,second);
		first=second;
		second=ans[cur];

	}
	cout<<cost<<endl;
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;


}
