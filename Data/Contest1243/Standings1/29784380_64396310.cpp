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
int frec[26];
string S, T;
vector<pair<int, int>> sol;

void solve(){
	cin >> N >> S >> T;
	
	for(int i=0; i < 26; i++)
		frec[i] = 0;
	
	for(auto i: S) frec[i - 'a']++;
	for(auto i: T) frec[i - 'a']++;
	
	for(int i=0; i < 26; i++)
		if( frec[i] % 2 == 1 ){
			printf("NO\n");
			return;	
		}
	
	sol.clear();
	for(int i=0; i < N; i++){
		if( S[i] != T[i] ){
			int a = -1, b = -1;
			
			for(int j=i+1; j < N; j++){
				if( S[i] == S[j] ){
					a = j;
					break;	
				}
				if( S[i] == T[j] ){
					b = j;
					break;	
				}	
			}
			
			if( a >= 0 ){
				sol.pb(mp(a, i));
				swap(T[i], S[a]);	
			}
			else if( b >= 0 ){
				sol.pb(mp(b, b));
				swap(T[b], S[b]);
				
				sol.pb(mp(b, i));
				swap(T[i], S[b]);	
			}	
		}
	}
	
	printf("YES\n%d\n", (int)sol.size());
	for(auto i: sol){
		printf("%d %d\n", i.fr+1, i.sc+1);
	}	
				
}

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    int t; scanf("%d", &t);
    while(t--) solve();
    
        

   return 0;
}
