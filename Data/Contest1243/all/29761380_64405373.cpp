#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//*find_by_order
//order_of_key

const int maxn = 1e6 + 5;

int n,m;
int ans = 0;
set<int> g[maxn];

set<int> notviz;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>n>>m;
  for (int i=0; i<m; i++) {
    int x,y; cin>>x>>y;
    g[x].insert(y);
    g[y].insert(x);
  }
  
  for (int i=1; i<=n; i++) {
    notviz.insert(i);
  }

  set<pair<int,int>> q;
  q.insert({0,1});

  while (!q.empty()) {
    
    auto cur = *q.begin();
    q.erase(q.begin());
    ans += cur.first;
    int at = cur.second;

    if (notviz.find(at) != notviz.end()) {
      notviz.erase(notviz.find(at));
    }

    set<int> toerase;
    for (int to: notviz) {
      int cost = 0;
      if (g[at].count(to)) {
	cost = 1;
      }
      if (cost == 0) {
	if (q.count({1,to})) {
	  q.erase({1,to});
	}
	toerase.insert(to);
	q.insert({0,to});
      } else {
	//cost == 1
	if (q.count({0,to})==0) {
	  q.insert({1,to});
	}
      }
    }

    for (int x: toerase) {
      if (notviz.count(x)) {
	notviz.erase(x);
      }
    }
  }

  out(ans);
  return 0;
}
