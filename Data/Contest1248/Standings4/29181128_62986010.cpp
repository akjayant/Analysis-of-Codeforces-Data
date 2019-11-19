#include <bits/stdc++.h>
using namespace std;
#define LL long long
 
 
LL a[300100];
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	
	int q = 1;
	//cin >> q;
	while( q-- ) {
	    int n ;
	    cin >> n;
	    
	    for(int i = 0; i < n ; i++ ) {
	        cin >> a[i];
	    }
	    sort( a, a + n);
	    LL x = 0, y = 0;
	    for(int i = n/2 ; i < n ;i++ ) {
	        x += a[i];
	    }
	    for(int i = 0 ; i < n/2 ;i++ ) {
	        y += a[i];
	    }
	    x = x * x;
	    y = y * y;
	    cout << x + y;
	}
	return 0;
}