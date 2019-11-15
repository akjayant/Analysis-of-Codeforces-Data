#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define pb push_back
#define f first
#define s second
#define BUFF ios::sync_with_stdio(false);

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int MAX = (int)1e5+10;

int main(){

  BUFF;

  int tt; cin >> tt;

  while( tt-- ){
	  int n;
	  string s, t;

	  cin >> n;
	  cin >> s;
	  cin >> t;

      vector<int> diff;
	  for( int i=0; i<n; i++ ){
		  if( s[i] != t[i] ){
			  diff.pb(i);
		  }
	  }

	  if( diff.size() > 2 ){
		  cout << "No" << endl;
		  continue;
	  }
	  if( diff.size() == 1 ){
		  cout << "No" << endl;
		  continue;
	  }
	  if( diff.size() == 0 ){
		  cout << "Yes" << endl;
		  continue;
	  }
	  
	  if( s[diff[0]] == s[diff[1]] and t[diff[1]] == t[diff[0]] ){
		  cout << "Yes" << endl;
	  }else{
		  cout << "No" << endl;
	  }
  }


  return 0;
}
