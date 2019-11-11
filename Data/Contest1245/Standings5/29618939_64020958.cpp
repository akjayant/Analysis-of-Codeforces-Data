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

int dp[MX];
char S[MX];
vector<int> vn, vu;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf(" %s", &S);
    int N = strlen(S);
    
    dp[0] = 1;
    for(int i=1; i<=N; i++){
		dp[i] = dp[i-1];
		
		if( i > 1 ) 
			dp[i] = (dp[i] + dp[i-2]) % MOD;  
	}
    
    int cu = 0, cn = 0;
    bool ok = false;
    
    for(int i=0; i < N; i++){
		if( S[i] == 'm' || S[i] == 'w' )
			ok = true;
			
		cu += S[i] == 'u';
		
		if( i == N-1 || S[i+1] != 'u' ){
			if( cu > 0 ) vu.pb(cu);
			cu = 0;	
		}		
	} 
    
    for(int i=0; i < N; i++){
		cn += S[i] == 'n';
		
		if( i == N-1 || S[i+1] != 'n' ){
			if( cn > 0 ) vn.pb(cn);
			cn = 0;	
		}		
	}
	
	int64 sol = 1;
	
	for(auto i: vu)
		sol = sol * dp[i] % MOD;	
	
	for(auto i: vn)
		sol = sol * dp[i] % MOD;	
	
	if( ok )
		sol = 0ll;
	
	printf("%lld\n", sol);
	
   return 0;
}
