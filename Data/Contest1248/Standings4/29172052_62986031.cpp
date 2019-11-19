///who is the king ??? *** << all of the programmers >> *** ///
/*
                  00                                                                                                            00
                 00                               00                                                                           00
            0000000000                           00                                                                           00
           0000000000   000       000           00                        000       000  000       000                       00
              00       0000     0000           00         000000         0000     0000  0000     0000   000000              00
             00       00 00   00 00    000    00        00000000        00 00   00 00  00 00   00 00  00000000       00000000
            00       00  00 00  00   00000   000000    00    000       00  00 00  00  00  00 00  00  00    000     0000000000
           00       00   000   00  00   00  00000000  00    0000      00   000   00  00   000   00  00    0000    00     0000
          00       00         00  00   00  00    00  00    00 00     00         00  00         00  00    00 00   00     00 00
         00  00   00         00   00000   00    00  00000000  00    00         00  00         00  00000000  00  000000000  00
        00  00   00         00    000    00    00   000000    00   00         00  00         00   000000    00  0000000    00
*/
#include <bits/stdc++.h>
using namespace std ;
#define int long long int
typedef long double ld ;
#define ff first
#define ss second
#define setp(t) cout << setprecision(t) << fixed ;
#define time_s printf("%fs.\n" , (float) clock () / CLOCKS_PER_SEC) ;
const int N = 1e5 + 10 ;
int32_t main() {
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	int t ;
	cin >> t ;
	while (t--) {
		int e1 = 0, e2 = 0 , o1 = 0 , o2 = 0 ;
		int n , a[N] = {} ;
		cin >> n ;
		for (int i = 0 ; i < n ; i++) {
			cin >> a[i] ;	
			if (a[i] % 2)
				o1++ ;
			else
				e1++ ;
		}
		int m , b[N] = {} ;
		cin >> m ;
		for (int i = 0 ; i < m ; i++) {
			cin >> b[i] ;	
			if (b[i] % 2)
				o2++ ;
			else
				e2++ ;
		}
		cout << (e1 * e2) + (o1 * o2) << "\n" ;
	}
}
