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
#define mp make_pair
#define d(X) cerr << #X << " = " << X << endl;
using namespace std;
using namespace __gnu_pbds;
typedef long long int64;
typedef unsigned long long unt64;

int cn, ca;
bool mk[MX];
vector<int> G[MX];
set<int> cero, uno;

int main(void){
	//freopen("a.in", "r", stdin);
	//~ freopen("a.out", "w", stdout);

	scanf("%d%d", &cn, &ca);
	for(int i=1, a, b; i<=ca; i++){
		scanf("%d%d", &a, &b);

		G[a].pb(b);
		G[b].pb(a);
	}

	sort(all(G[1]));
	for(int i=2; i<=cn; i++){
		uno.insert(i);
		sort(all(G[i]));
	}

	int sol = 0;
	for(cero.insert(1); !cero.empty() || !uno.empty(); ){
		int nod;

		if( !cero.empty() ){
			nod = *cero.begin();
			cero.erase(cero.begin());
		}
		else{
			assert(uno.size() > 0);
			nod = *uno.begin();
			sol++;
			uno.erase(uno.begin());
		}
        mk[nod] = true;

//		printf("nod = %d\n", nod);

		for(auto i: uno){
			if( !binary_search(all(G[nod]), i) ){
				cero.insert(i);
			}
		}

		uno.clear();
		for(auto i: G[nod]) if(!mk[i])
			uno.insert(i);
	}

	printf("%d\n", sol);


   return 0;
}
