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
string S, T;

void solve(){
	cin >> N >> S >> T;
	
	int c = 0;
	bool flag = false;
	char a, b;
		
	for(int i=0; i < (int)S.size(); i++){
		if( S[i] != T[i] ){
			c++;
			
			if( c == 1 ){
				a = S[i], b = T[i];	
			}
			else if( c == 2 && a == S[i] && b == T[i] ){
				flag = true;
			}
			if( c > 2 ) flag = false;
		}
	}
	
	printf(flag ? "YES\n" : "NO\n");		
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    int t; scanf("%d", &t);
    while(t--) solve();
    
        

   return 0;
}
