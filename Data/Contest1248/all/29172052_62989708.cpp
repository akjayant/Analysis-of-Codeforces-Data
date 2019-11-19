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
vector <int> v ;
int32_t main() {
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	int n , mx = 0 ;
	cin >> n ;
	for (int i = 0 ; i < n ; i++) {
		int x ;
		cin >> x ;
		v.push_back(x) ;
		mx += x ;
	}
	sort(v.begin() , v.end()) ;
	int x = (n / 2) , y = v.size() - 1 , fin = 0 ;
	if (n % 2)
		x++ ;
	while (x--) {
		fin += v[y] ;
		y-- ;
	}
	return cout << (fin * fin) + ((mx - fin) * (mx - fin)) , 0 ;
	
}
