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

	  int n; cin >> n;
	  string s, t;
	  cin >> s >> t;

	  map<char, int> hist;

	  for( char c : s ){
		  hist[c]++;
	  }
	  for( char c : t ){
		  hist[c]++;
	  }

	  bool sai = false;
	  for( auto p : hist ){
		  if( p.s%2 ){
			  cout << "No" << endl;
			  sai = true;
			  break;
		  }
	  }

	  if( sai ){
		  continue;
	  }


	  vector<pair<int, int>> resp;

	  for( int i=0; i<n; i++ ){
		  if( s[i] == t[i] ){
			  continue;
		  }
		  char c = s[i];

		  bool foi = false;
		  for( int j=i+1; j<n; j++ ){
			  if( s[j] == c ){
				  //cout << j+1 << " " << i+1 << endl;
				  resp.pb({j+1, i+1});
				  swap(t[i], s[j]);
				  foi = true;
				  break;
			  }
		  }

		  if( foi ) continue;

		  for( int j=i+1; j<n; j++ ){
			  if( t[j] == c ){
				  resp.pb({n, j+1});
				  //cout << n << " " << j+1 << endl;
				  swap(s[n-1], t[j]);
				  resp.pb({n, i+1});
				  //cout << n << " " << i+1 << endl;
				  swap(s[n-1], t[i]);
				  break;
			  }
		  }
	  }

	  if( s != t ){
		  cout << "No" << endl;
		  continue;
	  }

	  cout << "Yes" << endl;
	  cout << resp.size() << endl;
	  for( auto e : resp ){
		  cout << e.f << " " << e.s << endl;
	  }

  }


  return 0;
}
