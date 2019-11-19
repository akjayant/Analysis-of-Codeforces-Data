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

  ll n; cin >> n;

  if( n == 1 ){
	  cout << 1 << endl;
	  return 0;
  }

  map<ll, int> d;

  for( ll i=2; i*i<=n; i++ ){
	  while( n%i == 0 ){
		  n /= i;
		  d[i]++;
	  }
  }

  if( n != 1 ){
	  d[n]++;
  }

  if( d.size() > 1 ){
	  cout << 1 << endl;
  }else{
	  auto p = *d.begin();
	  cout << p.f << endl;
  }

  return 0;
}
