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

  int t; cin >> t;

  while( t-- ){
	  int n; cin >> n;
	  vector<int> v;

	  for( int i=0; i<n; i++ ){
		  int x; cin >> x;
		  v.pb(x);
	  }

	  sort(v.begin(), v.end());
	  reverse(v.begin(), v.end());

      int mx=0;
	  for( int i=0; i<n; i++ ){
		  mx = max(mx, min(i+1, v[i]));
	  }

	  cout << mx << endl;
  }

  return 0;
}
