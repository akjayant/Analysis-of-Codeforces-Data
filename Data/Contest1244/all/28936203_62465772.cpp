#include "bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long int
#define int ll
//#define slld(t) scanf("%lld",&t)
//#define sd(t) scanf("%d",&t)
//#define pd(t) printf("%d\n",t)
//#define plld(t) printf("%lld\n",t)
#define vec vector < int >
#define vecp vector < pair < int , int > >
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define pii pair < int , int >
#define pll pair < ll , ll > 
#define pdd pair<double , double>
#define debug(x)   cerr<<#x<<": "<<x<<endl
#define mod  1000000007
#define N    1000010
#define mod1 1000000007
#define mod2 998244353
#define bitcnt __builtin_popcountll
#define PI acos(-1)
// #define mid  (l + r )/2
#define s3   1.73205080757
const int inf = (int)1e18+10 ;
const int MAX= 200005;

signed main(){
  fast;
 
  int t , a , b , c , d , x , y , k;
  cin >> t;
  while(t--){
  	   cin >> a >> b >> c >> d >> k;
  	   if(a%c == 0) x = (a/c);
  	   else x = (a/c) + 1;
  	   if(b%d == 0) y = (b/d);
  	   else y = (b/d) + 1;
  	   if(x + y <= k){
  	   	cout << x << " " << y << endl;
  	   }
  	   else
  	   	cout << -1 << endl;
  }
 // check for n=1 edge case 
}
