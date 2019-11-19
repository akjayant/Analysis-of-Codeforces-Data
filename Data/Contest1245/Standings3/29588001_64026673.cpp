#include <bits/stdc++.h>
using namespace std;

const int N=2e3+3;
typedef long long ll;
typedef pair<ll,int> pli;

int n;
int tr[N];
bool visited[N];
ll x[N],y[N],c[N],k[N];
ll d[N];
ll ans;

priority_queue< pli, vector<pli>, greater<pli> > q;

inline ll dis(int &i, int &j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

void prim(){
    for (int i=1; i<=n; ++i){
        d[i]=c[i];
        q.push(pli(d[i],i));
    }
    int u;
    ll w;
    while(!q.empty()){
        u = q.top().second;
        w = q.top().first;
        q.pop();
        if (w!=d[u]) continue;
        ans+=d[u];
        visited[u]=1;
        for (int i=1; i<=n; ++i)
        if (!visited[i])
        if ((k[u]+k[i])*dis(u,i)<d[i]){
            tr[i]=u;
            d[i]=(k[u]+k[i])*dis(u,i);
            q.push(pli(d[i],i));
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for (int i=1; i<=n; ++i)
	    cin>>x[i]>>y[i];
	for (int i=1; i<=n; ++i)
	    cin>>c[i];
	for (int i=1; i<=n; ++i)
	    cin>>k[i];
	prim();
	cout<<ans<<'\n';
	int tmp=0;
	for (int i=1; i<=n; ++i)
	    tmp+=(tr[i]==0);
	cout<<tmp<<'\n';
	for (int i=1; i<=n; ++i)
	if (tr[i]==0)
	    cout<<i<<' ';
	cout<<'\n';
	cout<<n-tmp<<'\n';
	for (int i=1; i<=n; ++i)
	if (tr[i])
	    cout<<i<<' '<<tr[i]<<'\n';
}