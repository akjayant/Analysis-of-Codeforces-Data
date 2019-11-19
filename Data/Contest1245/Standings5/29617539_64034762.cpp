#include<bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define pb push_back
#define ms(a, x) memset(a, x, sizeof(a))

#define endl '\n'
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> pii;
struct edge{
	int s,e,type;
	ll c;
	edge(int s_=0,int e_=0,ll cc=0,int tt=0):s(s_),e(e_),c(cc),type(tt){}
	bool operator<(const edge& a)const{
		return c>a.c;
	}
};
const int N=2005;
//~ vector<edge> E[N];
ll dis(pii a,pii b){
	return abs(a.first-b.first)+abs(a.second-b.second);
}
bool vis[N];
priority_queue<edge> q;
	vector<pii> bwire;
	vector<int> bsta;
pii point[N];
int cost[N],wire[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin>>n;
	
	forn(i,n) cin>>point[i].first>>point[i].second;
	
	int start;
	int mn=INF;
	forn(i,n){
		cin>>cost[i];
		if(cost[i]<mn){
			mn=cost[i];
			start=i;
		}
	}
	forn(i,n) cin>>wire[i];
	//~ forn(i,n){
		//~ forn(j,n){
			//~ if(i==j) continue;
			//~ E[i].pb({i,j,dis(point[i],point[j])*(wire[i]+wire[j]),1});
			//~ E[i].pb({i,j,cost[j],2});
		//~ }
	//~ }
	
	q.push({start,start,0,0});
	bsta.pb(start+1);
	ll totcost=cost[start];
	while(!q.empty()){
		edge tmp=q.top();
		q.pop();
		int end=tmp.e;
		if(vis[end]) continue;
		vis[end]=1;
		totcost+=tmp.c;
		if(tmp.type==1) bwire.pb({tmp.s+1,tmp.e+1});
		else if(tmp.type==2) bsta.pb(end+1);
		//~ for(auto it:E[end]) q.push(it);
		forn(j,n){
			if(end==j) continue;
			if(vis[j]) continue;
			q.push({end,j,dis(point[end],point[j])*(wire[end]+wire[j]),1});
			q.push({end,j,cost[j],2});
		}
	}
	cout<<totcost<<endl;
	cout<<bsta.size()<<endl;
	for(auto it:bsta) cout<<it<<' ';
	cout<<endl<<bwire.size()<<endl;
	for(auto it:bwire) cout<<it.first<<' '<<it.second<<endl;
    return 0;
}
