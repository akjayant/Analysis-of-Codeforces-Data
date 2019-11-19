/* Code by Saborit */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast") 
#define MX 100005
#define INF (1<<30)
#define EPS 1e-9
#define MOD 1000000007
#define mid (x+xend)/2
#define izq nod*2
#define der nod*2+1
#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
#define unique(X) (X).resize(unique(all(X)) - (X).begin())
#define d(X) cerr << #X << " = " << X << endl;
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

struct edge{
	int nod, nwn;
	int64 cost;
	
	bool operator < (const edge& p)const{
		return cost < p.cost;	
	}
};

int N;
int C[MX], K[MX], X[MX], Y[MX], SET[MX];
int64 mst;
vector<edge> G;
vector<int> cc;
vector<pair<int, int>> sol;

inline int dist(int i, int j){
	return abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
}

int find_set(int nod){
	if( SET[nod] != nod )
		return SET[nod] = find_set(SET[nod]);
	return nod;	
}

void join_set(int nod, int nwn){
	if( C[nod] < C[nwn] ){
		SET[nwn] = nod;
		C[nwn] = C[nod];
	}
	else{
		SET[nod] = nwn;
		C[nod] = C[nwn];	
	}
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
		scanf("%d%d", &X[i], &Y[i]);
		
	for(int i=1; i<=N; i++)
		scanf("%d", &C[i]);
     
    for(int i=1; i<=N; i++)
		scanf("%d", &K[i]);
		
	for(int i=1; i<=N; i++)
		for(int j=i+1; j<=N; j++)
			G.pb({i, j, (int64)(K[i] + K[j]) * dist(i, j)});
    
    for(int i=1; i<=N; i++){
		SET[i] = i;
	}
	
	sort(all(G));
	
	for(auto e: G){
		int setnod = find_set(e.nod);
		int setnwn = find_set(e.nwn);
		
		if( setnod != setnwn ){
			if( max(C[setnod], C[setnwn]) > e.cost ){
				sol.pb(make_pair(e.nod, e.nwn));
				mst += e.cost;
				
				join_set(setnod, setnwn);	
			}
		}
	}
	
	for(int i=1; i<=N; i++){
		if( SET[i] == i ){
			mst	+= C[i];
			cc.pb(i);
		}
	}
	
	printf("%lld\n%d\n", mst, (int)cc.size());
	for(int i=0; i < (int)cc.size(); i++)
		printf(i == (int)cc.size() -1 ? "%d\n" : "%d ", cc[i]);	
	printf("%d\n", (int)sol.size());    
	for(auto i: sol)
		printf("%d %d\n", i.fr, i.sc);

   return 0;
}
