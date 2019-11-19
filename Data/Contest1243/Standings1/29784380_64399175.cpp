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

int64 N;

int main(void){
    //~ freopen("a.in", "r", stdin);
    //~ freopen("a.out", "w", stdout);
    
    scanf("%lld", &N);
    
    int64 gcd = N; 
    for(int i=2; (int64)i*i<=N; i++) if( N % i == 0 ){
		gcd = __gcd(gcd, (int64)i);
		gcd = __gcd(gcd, N/i);
	}
    
    printf("%lld\n", gcd);
     
        

   return 0;
}
