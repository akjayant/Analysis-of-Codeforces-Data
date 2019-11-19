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
const int N = 1e5 + 10 , M = 1e9 + 7 ;
int f[N] ;
int32_t main() {
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	int n , m ;
	cin >> n >> m ;
	f[0] = 1 ;
	f[1] = 1 ;
	for (int i = 2 ; i <= max(m , n) ; i++)
		f[i] = f[i - 1] + f[i - 2] , f[i] %= M ;
	return cout << ((2 * f[m]) + (2 * f[n]) - 2) % M , 0 ;
}
