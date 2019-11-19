#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

//#define int long long

using namespace std;

const int MAXN = ( int ) 1e6 + 10;

int a[MAXN], mns[MAXN];
int n, m;
int i1, i2;
int ans;
void check( int i, int j )
{
      multiset<int> ml;
      int cnt = 0;
      for( int i = 1; i <= n; i++ ){
            cnt += a[i];
      }
      mns[n] = cnt;
      cnt -= a[n];
      for( int i = n - 1; i >= 1; i-- ){
            mns[i] = min( mns[i + 1], cnt );
            cnt -= a[i];
      }
      int cntt = cnt;
      int res = 0;
      if( mns[1] >= 0 )
            res++;
      cnt = a[1];
      cntt -= a[1];

      int mn = a[1];

      for( int i = 2; i <= n; i++ ){
            if( mns[i] - cnt >= 0 && cntt + mn >= 0 )
                  res++ ;
            cnt += a[i];
            cntt -= a[i];
            mn = min( mn, cnt );
      }

      if( res > ans ){
            ans = res;
            i1 = i;
            i2 = j;
      }
}
void solution()
{
      string s;

      cin >> n >> s;
      int cnt = 0;
      for( int i = 0; i < n; i++ ) {
            if( s[i] == '(' )
                  a[i + 1] = 1;
            else 
                  a[i + 1] = -1;
            cnt += a[i + 1];
      }
      if( cnt ){
            cout << 0 << endl;
            cout << 1 << " " << 1 << endl;
            return;
      }
      for( int i = 1; i <= n; i++ ){
            for( int j = i; j <= n; j++ ){
                  swap( a[i], a[j] );
                  check( i, j );
                  swap( a[i], a[j] );
            }
      }
      cout << ans << endl;    
      cout << i1 << " " << i2 << endl;
      
}
int32_t main()
{

      ios::sync_with_stdio( 0 );
      
      int t = 1;
      //cin >> t;
      
      while( t-- ) solution();

}