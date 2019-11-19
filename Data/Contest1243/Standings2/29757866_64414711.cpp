#include<bits/stdc++.h>
using namespace std;
const int N=200100;
typedef long long ll;
const ll MOD=1e9+7LL;
int pai[N],rk[N];
int fin(int x)
{
	if(x==pai[x])
		return x;
	return pai[x]=fin(pai[x]);
}
void join(int a,int b)
{
	a=fin(a),b=fin(b);
	if(a!=b)
	{
		if(rk[a]>rk[b])
			swap(a,b);
		pai[a]=b;
		rk[b]+=rk[a];
	}
}
set<int> lista[N];
int n; // number of nodes

int rs=0;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin>>n>>m;
    int u,v;
    for (int i = 0; i < m; ++i)
    {
    	cin>>u>>v;
    	u--,v--;
    	lista[u].insert(v);
    	lista[v].insert(u);
    }
    set<pair<int,int>> f;
    for (int i = 0; i < n; ++i)
	 {
	 	f.insert({-lista[i].size(),i});
	 } 
	while(!f.empty())
	{
		pair<int,int> at=*f.begin();
		f.erase(at);
		if((-at.first)==f.size() && at.first!=0){
			// cout<<at.first+1<<" "<<f.size()<<"\n";
			rs++;
		}
		for(auto u:lista[at.second])
		{
			f.erase({-lista[u].size(),u});
			lista[u].erase(at.second);
			f.insert({-lista[u].size(),u});
		}
	}
    cout<<rs<<"\n";
    return 0;   
}