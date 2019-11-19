#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)

using namespace std;

typedef long long ll;

bool LT(double a,double b) { return !equals(a,b) && a < b; }
bool LTE(double a,double b) { return equals(a,b) || a < b; }

bool debug = 0;


int par[1000];
int find(int x) {
  if( par[x] == x ) return x;
  return par[x] = find(par[x]);
}
void unite(int x,int y) {
  x = find(x),y = find(y);
  if( x != y ) par[x] = y;
}

bool isPrime(ll v) {
  if( v == 0 || v == 1 ) return false;
  if( v == 2LL ) return true;
  for(ll j=2;j*j<=v;++j) {
    if( v % j == 0 ) {
      return false;
    }
  }
  return true;
}

map<ll,int> prime_factor(ll n) {
  map<ll,int> res;
  for(ll i=2;i*i<=n;i++) {
    while(n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if(n != 1)res[n] = 1;
  return res;
}

void compute(ll n) {
  if( isPrime(n) ) {
    cout <<  n << endl;
  } else {
    map<ll,int> mp = prime_factor(n);
    ll v = -1;
    int cnt = 0;
    for(auto w : mp) {
      v = w.first;
      ++cnt;
    }
    if( cnt == 1 ) {
      cout << v << endl;
    } else {
      cout << 1 << endl;
    }
  }
}



int main() {
  ll n;
  cin >> n;
  if( 0 ) {
  rep(i,n) par[i] = i;
  rep(i,n) {
    REP(j,i+1,n) {
      int d = abs(j-i);
      if( d > 1 ) {
	if( n % d == 0 ) unite(i,j);
      }
    }
  }
  rep(i,n) {
    cout << find(i) << " "; 
  } puts("");
  }
  compute(n);
  return 0;
}
