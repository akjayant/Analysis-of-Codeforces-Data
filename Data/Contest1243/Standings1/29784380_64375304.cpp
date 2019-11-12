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

int N;
int A[MX];

void solve(){
	scanf("%d", &N);
    for(int i=1; i<=N; i++)
		scanf("%d", &A[i]);
		
	sort(A+1, A+N+1, greater<int>());
	
	int sol = 0;
	
	for(int i=1; i<=N; i++)
		if( A[i] >= i )
			sol = max(sol, i);
			
	printf("%d\n", sol);		
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    int t; scanf("%d", &t);
    while(t--) solve();
    
        

   return 0;
}
