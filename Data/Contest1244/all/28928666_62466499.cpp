#include "bits/stdc++.h"
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 100000000007;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

// Print fn to print array

int main(){
	int t;
	cin >> t;
	while(t--){
    	int a,b,c,d,k;
    	cin >> a >> b >> c >> d >> k;
    	double q,w;
    	q = (double)a/c;
    	w = (double)b/d;
    	if(q!=(int)q) q++;
    	if(w!=(int)w) w++;
    	ll r = (ll)q+(ll)w;
    	if(r>k){
    		cout << -1 << endl;
    	}
    	else cout << (ll)q << " " << (ll)w << endl;
	}	
	return 0;
}
