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

int tot=0;
set<int> to_visit;
set<pair<int, int>> edges;

int main(){

  BUFF;

  int n, m; cin >> n >> m;

  for( int i=0; i<m; i++ ){
	  int a, b; cin >> a >> b;
	  edges.insert({a, b});
	  edges.insert({b, a});
  }

  for( int i=1; i<=n; i++ ){
	  to_visit.insert(i);
  }


  queue<int> q;

  while( to_visit.size() ){
  
  q.push(*to_visit.begin());
  to_visit.erase(to_visit.begin());
  tot++;

  while( q.size() ){

	  int at = q.front();
	  q.pop();

      vector<int> rem;
	  for( int e : to_visit ){
		  if( !edges.count({at, e}) ){
			  rem.pb(e);
		  }
	  }

	  for( int e : rem ){
		  to_visit.erase(e);
		  q.push(e);
	  }
  }
  
  }

  cout << tot-1 << endl;


  return 0;
}
