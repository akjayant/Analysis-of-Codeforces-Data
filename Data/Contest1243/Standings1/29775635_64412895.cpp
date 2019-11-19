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
const int N = 101'000;

struct upii {
  ll x,y;
  bool operator==(const upii& o) const {
    return (x == o.x and y == o.y) or (x == o.y and y == o.x);
  }
};

struct PairHash {
  ll operator()(const upii& p) const {
    return p.x*p.y;
  }
};

unordered_set<upii, PairHash> edges;
unordered_set<int> unvisited;

int main () {
  fastio;
  int n,m;

  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    unvisited.insert(i);

  for(int i = 0 ; i < m; i++) {
    ll a,b;
    cin >> a >> b;
    edges.insert({a,b});
  }

  stack<int> q;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(unvisited.count(i)) {
      ans++;
      q.push(i);
      unvisited.erase(i);
      while(q.size()) {
        int x = q.top(); q.pop();
        for(auto it = unvisited.begin(); it != unvisited.end();) {
          if(!edges.count({x, *it})) {
            q.push(*it);
            it = unvisited.erase(it);
          }
          else it++;
        }
      }
    }
  }
  cout << ans-1 << endl;
  return 0;
}
