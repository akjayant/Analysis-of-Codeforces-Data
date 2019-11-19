#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 1e5 + 1;
int n , m , k , cnt_n[MAXN] , cnt_m[MAXN] , cot_n , cot_m;
int main( void ) {
  scanf("%d%d%d",&n,&m,&k);
  for( int i = 1 , x , y ; i <= k ; ++i ) {
    scanf("%d%d",&x,&y);
    ++cnt_n[x] , ++cnt_m[y];
  }
  int left = 1 , right = m , up = 1 , down = n , dir = 1;
  while( right >= left && cnt_m[right]  == ( down - up + 1 ) ) --right , ++cot_m;
  while( down >= up && ( cnt_n[down] - cot_m ) == ( right - left + 1 ) ) --down , ++cot_n;
  while( left <= right && up <= down ) {
    if( dir == 1 ) {
      while( right >= left && ( cnt_m[right] - cot_n ) == ( down - up + 1 ) ) --right , ++cot_m;
      while( down >= up && ( cnt_n[down] - cot_m ) == ( right - left + 1 ) ) --down , ++cot_n;
      if( right < left ) break;
      if( up > down ) break;
      if( ( cnt_m[right] - cot_n ) > 0 ) return puts("No"),0;
      ++up;
      dir = 2;
    } else if( dir == 2 ) {
      while( down >= up && ( cnt_n[down] - cot_m ) == ( right - left + 1 ) ) --down , ++cot_n;
      while( left <= right && ( cnt_m[left] - cot_n ) == ( down - up + 1 ) ) ++left , ++cot_m;
      if( down < up ) break;
      if( right < left ) break;
      if( ( cnt_n[down] - cot_m ) > 0 ) return puts("No"),0;
      --right;
      dir = 3;
    } else if( dir == 3 ) {
      while( left <= right && ( cnt_m[left] - cot_n ) == ( down - up + 1 ) ) ++left , ++cot_m;
      while( down >= up && ( cnt_n[up] - cot_m ) == ( right - left + 1 ) ) ++up , ++cot_n;
      if( right < left ) break;
      if( up > down ) break;
      if( ( cnt_m[left] - cot_n ) > 0 ) return puts("No"),0;
      --down;
      dir = 4;
    } else {
      while( down >= up && ( cnt_n[up] - cot_m ) == ( right - left + 1 ) ) ++up , ++cot_n;
      while( right >= left && ( cnt_m[right] - cot_n ) == ( down - up + 1 ) ) --right , ++cot_m;
      if( down < up ) break;
      if( right < left ) break;
      if( ( cnt_n[up] - cot_m ) > 0 ) return puts("No"),0;
      ++left;
      dir = 1;
    }
  }
  return puts("Yes"),0;
  return 0;
}
