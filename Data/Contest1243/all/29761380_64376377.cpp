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


bool solve() {
  int n; cin>>n;
  string s,t; cin>>s>>t;
  if (s==t) return true;
  vector<int> v;
  for (int i=0; i<n; i++) {
    if (s[i]==t[i]) continue;
    v.push_back(i);
  }
  if (int(v.size()) != 2) return false;
  return s[v[0]]==s[v[1]] && t[v[0]]==t[v[1]];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
  cout << fixed << setprecision(12);

  int t; cin>>t;
  while (t--) {
    if (solve()) {
      cout<<"Yes\n";
    } else {
      cout<<"No\n";
    }
  }
    return 0;
  }
