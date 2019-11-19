#include <bits/stdc++.h>
using namespace std;
#define LL long long
 
 
LL a[300100];
LL b[300100];
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	
	int q = 1;
	cin >> q;
	while( q-- ) {
	    int n ;
	    cin >> n;
	    LL e = 0, o = 0;
	    for(int i = 0; i < n ; i++ ) {
	        cin >> a[i];
	        if ( a[i] & 1 ) {
	            o++;
	        } 
	        else {
	            e++;
	        }
	    }
	    
	    int m ;
	    cin >> m;
	    LL an = 0;
	    for(int i = 0; i < m ; i++ ) {
	        cin >> b[i];
	        if ( b[i] & 1 ) {
	            an += o;
	        } 
	        else {
	            an += e;
	        }
	    }
	    cout << an << "\n";
	}
	return 0;
}