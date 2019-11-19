//I read the news today, oh boy
//About a lucky man who made the grade
 
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cerr << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for(int i = int(a); i < int(b); ++i)
#define roF(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N=1e5+5;
const ll INF = 1e18;

ii coords[N];
vector <pair<ll, ii> > E;
int p[N];
ll cost[N], k[N];

int find(int x){
	return p[x]==x ? x : p[x]=find(p[x]);
}

void uni(int u, int v){
	int x = find(u), y=find(v);
	if(cost[x]<cost[y]) swap(x,y);
	p[x]=y;
}

int main(){
	fastio;
	int n; cin>>n;
	For(i,0,n) cin>>coords[i].ff>>coords[i].ss;
	For(i,0,n) p[i]=i;
	ll tot=0;
	For(i,0,n){
		cin>>cost[i];
		tot+=cost[i];
	}
	For(i,0,n) cin>>k[i];
	For(i,0,n)
		For(j,i+1,n){
			ll w = (k[i]+k[j])*(abs(coords[i].ff-coords[j].ff) + abs(coords[i].ss-coords[j].ss));
			E.pb(mp(w,mp(i,j)));
			E.pb(mp(w,mp(j,i)));
		}
	sort(all(E));
	vii ANS;
	int comps=n;
	for(auto e: E){
		ll w = e.ff;
		int u = e.ss.ff;
		int v = e.ss.ss;
		int x = find(u), y = find(v);
		if(x!=y && w<max(cost[x],cost[y])){
			tot = tot-max(cost[x],cost[y])+w;
			ANS.pb(mp(u+1,v+1));
			uni(x,y);
			comps--;
		}
	}
	cout<<tot<<endl;
	set<int> S;
	cout<<comps<<endl;
	For(i,0,n) if(!S.count(p[i])){
		cout<<p[i]+1<<" ";
		S.insert(p[i]);
	}
	cout<<endl;
	cout<<sz(ANS)<<endl;
	for(ii ans : ANS) cout<<ans.ff<<" "<<ans.ss<<endl;
	
	return 0;
}