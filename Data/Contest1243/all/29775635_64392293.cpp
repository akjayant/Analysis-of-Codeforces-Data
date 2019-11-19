#include <bits/stdc++.h>

#define st first
#define nd second
#define pb push_back
#define mp make_pair

#define cl(x,y) memset(x, y, sizeof(x))
#define dbs(x) cerr << x << endl;
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<
#define fori(i,a,b) for(int i = a; i < b; i++)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fileio freopen("input.txt","r",stdin); freopen("output.txt", "w",stdout);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, M = 1e9+7;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1), EPS = 1e-9;
// const int N = ;

set<int> d;

int main () {
  fastio;
  ll n;
  cin >> n;
  ll nn = n;
  for(ll i = 2; i*i <= n; i++) {
    if(n%i == 0) {
      d.insert(i);
      while(n%i == 0) n /= i;
      if(n > 1) d.insert(n);  
      break;    
    }
  }
  if(d.size() > 1) {
    cout << 1 << '\n';
  }
  else if (d.empty()) {
    cout << n << '\n';
  }
  else {
    cout << *d.begin() << '\n';
  }
  return 0;
}
