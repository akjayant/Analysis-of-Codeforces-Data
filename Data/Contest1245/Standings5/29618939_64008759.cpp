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

int N, cant, r, p, s;
char S[MX], sol[MX];

void solve(){
	scanf("%d%d%d%d", &N, &r, &p, &s);
	scanf(" %s", S);
	
	for(int i=0; i < N; i++)
		sol[i] = 'A';
	
	cant = 0;
	for(int i=0; i < N; i++){
		if( S[i] == 'R' && p > 0 ){
			sol[i] = 'P';
			p--;	
			cant++;
		}	
		else if( S[i] == 'P' && s > 0 ){
			sol[i] = 'S';
			s--;	
			cant++;
		}
		else if( S[i] == 'S' && r > 0 ){
			sol[i] = 'R';
			r--;	
			cant++;
		}
			
	}
	
	for(int i=0; i < N; i++){
		if( sol[i] == 'A' ){
			if( p > 0 ){
				sol[i] = 'P';
				p--;	
			}	
			else if( r > 0 ){
				sol[i] = 'R';
				r--;	
			}
			else if( s > 0 ){
				sol[i] = 'S';
				s--;	
			}
		}	
	}
	
	sol[N] = '\0';
	if( 2*cant >= N )
		printf("YES\n%s\n", sol);
	else 
		printf("NO\n");
		
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    int t; scanf("%d", &t);
    while( t-- ) solve();
     
        

   return 0;
}
