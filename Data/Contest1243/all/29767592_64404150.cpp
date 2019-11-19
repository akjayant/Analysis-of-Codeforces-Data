#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5;
const int inf=1e9;
typedef pair<int,int> pii;

int n,m;
multiset<int> visited;
int deg[N],d[N];
set<int> se[N];
stack<int> st;
priority_queue<pii,vector<pii>, greater<pii> > q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1; i<=m; ++i){
	    int u,v;
	    cin>>u>>v;
	    se[u].insert(v);
	    deg[u]++;
	    se[v].insert(u);
	    deg[v]++;
	}
	int x=1;
	for (int i=1; i<=n; ++i){
	    if (deg[i]<deg[x])
	        x=i;
	    d[i]=inf;
	}
	q.push(pii(0,x));
	for (int i=1; i<=n; ++i)
	if (i!=x) visited.insert(i);
	d[x]=0;
	int u,du;
	int ans=0;
	while(!q.empty()){
	    du = q.top().first;
	    u = q.top().second;
	    q.pop();
	    if (d[u]!=du) continue;
	    ans+=d[u];
	    d[u]=0;
	    
	    for (int i:visited)
	    if (!se[u].count(i) && d[i]>0){
	        d[i]=0;
	        q.push(pii(d[i],i));
    	    st.push(i);
	    }
	    while(!st.empty()){
	        visited.erase(st.top());
	        st.pop();
	    }
	    for(auto v: se[u])
            if (d[v]>1)
            {
                d[v]=1;
                q.push(pii(d[v],v));
            }
	}
	cout<<ans;
}
