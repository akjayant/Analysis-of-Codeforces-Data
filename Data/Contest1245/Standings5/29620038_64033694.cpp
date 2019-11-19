#include <bits/stdc++.h>
#define int long long int
using namespace std ;

const int N=2005 ;
int pa[N] ;
int sz[N] ;

int find(int node)
{
	if(pa[node]==-1) return node ;
	else{
		int par=find(pa[node]) ;
		pa[node]=par;
		return par ;
	}
}

void merge(int a, int b)
{
	if(sz[a]>sz[b]) swap(a,b) ;
	pa[a]=b ;
	sz[b]+=sz[a] ;
}

vector<pair<int, int> > connections ;
vector<int> powerStations ;

main()
{
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;

	int n ;
	cin >> n ;
	sz[0]=1 ;
	int x[n+1]; int y[n+1] ; int c[n+1] ; int k[n+1] ;
	for(int i=1 ; i<=n ; i++){
		cin >> x[i] >> y[i] ;
		sz[i]=1 ;
	}
	memset(pa, -1, sizeof(pa)) ;

	for(int i=1 ; i<=n ; i++)  cin >> c[i] ;
	for(int i=1 ; i<=n ; i++)  cin >> k[i] ;	
	
	vector<pair<int , pair<int, int> > > edges;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=n ; j++){
			edges.push_back({(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])), {i,j}}) ;
		}
	}
	for(int i=1 ; i<=n ; i++){
		edges.push_back({c[i], {0,i}}) ;
	}

	sort(edges.begin(), edges.end()) ;

	int totalcost=0 ;
	int left=n ;
	for(int i=0 ; left>0 ; i++){
		int cost=edges[i].first ;
		int a=edges[i].second.first ;
		int b=edges[i].second.second ;
		int ca=find(a) ;
		int cb=find(b) ;
		if(ca==cb) continue ;
		totalcost+=cost ;
		merge(ca, cb) ;
		if(a==0){
			powerStations.push_back(b) ;
		}
		else{
			connections.push_back({a,b}) ;
		}
		left-- ;
	}

	cout << totalcost << endl ;
	cout << powerStations.size() << endl ;
	for(int x:powerStations) cout << x << " " ;
	cout << endl ;
	cout << connections.size() << endl;
	for(auto p: connections) cout << p.first << " " << p.second << endl ;

	return 0 ;
}