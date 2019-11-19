#include <bits/stdc++.h>
using namespace std ;
template < class R > inline void Readin( R &K ) {bool F=K=0;char C=getchar();while(C<'0'||C>'9')
{if(C=='-')F=1;C=getchar();}while(C<='9'&&C>='0')K=(K<<1)+(K<<3)+C-'0',C=getchar();if(F)K=-K;}
template < class R > inline bool Checkmax( R &A , R B ) { return A < B ? A = B , 1 : 0 ; }
template < class R > inline bool Checkmin( R &A , R B ) { return A > B ? A = B , 1 : 0 ; }
int main() {
	int T ;
	Readin( T ) ;
	while( T-- ) {
		int A , B , C , D , K ;
		cin >> A >> B >> C >> D >> K ;
		for(register int X = 0 ; X <= 100 ; ++X ) {
			for(register int Y = 0 ; Y <= 100 ; ++Y ) {
				if( X + Y <= K and X * C >= A and Y * D >= B ) {
					cout << X << ' ' << Y << endl ;
					goto end ;
				}
			}
		}
		cout << -1 << endl ;
		end:;
	}
	return 0 ;
}