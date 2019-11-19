#include<bits/stdc++.h>
#define ll long long
#define N 1000050
#define pb push_back
#define all(v) v.begin(),v.end()
using namespace std;
vector<int> adj[N],adr[N];
int vis[N];
int comp[N];  //component no i.e.. answer after compression
vector< int > jury; vector< int > cat;
vector<int> topSortArr;

void topSort(int i){
	vis[i]=1;
	for(int v:adj[i])
		if(!vis[v])
			topSort(v);
	topSortArr.pb(i);
}

void scc_dfs(int i,int c){
	comp[i]=c;
	vis[i]=1;
	for(int v:adr[i])
		if(!vis[v]) scc_dfs(v,c);
}

// fills comp and returns number of components
int graphCompress(int n){
	topSortArr.clear();
	for(int i=0;i<n;i++) vis[i]=0;
	for(int i=0;i<n;i++){
		if(!vis[i]) topSort(i);
	}
	reverse(all(topSortArr));
	for(int i=0;i<n;i++) vis[i]=0;

	int componentNo=0;
	for(int i:topSortArr){
		if(!vis[i]){
			scc_dfs(i,componentNo);
			componentNo++;
		}
	}
	for(int i=0;i<n;i++) vis[i]=0;
	return componentNo; // no of components
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            if(u==v)continue;
            u--; v--;
            adj[u].push_back(v);
            adr[v].push_back(u);
    }
   int v= graphCompress(n);
    if(v==1){
        cout<<"No";
    }
    else{
            cout<<"Yes\n";

        for(int i=0;i<n;i++)
            if(comp[i]==v-1)jury.push_back(i);
            else cat.push_back(i);
        int js=jury.size(); int rem=n-js;
        cout<<js<<" "<<rem<<"\n";
        for(int i=0;i<jury.size();i++)
            cout<<jury[i]+1<<" ";
        cout<<"\n";
        for(int i=0;i<rem;i++)
            cout<<cat[i]+1<<" ";
    }
    jury.clear();
    cat.clear();
    for(int i=0;i<n;i++){
        vis[i]=0;
        adj[i].clear();
        adr[i].clear();
        comp[i]=0;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}
