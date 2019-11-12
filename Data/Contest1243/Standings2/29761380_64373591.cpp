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

int solve() {
  int n; cin>>n;
  vector<int> v(n);
  for (int i=0; i<n; i++) {
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  int ans = 0;
  for (int i=0; i<n; i++) {
    if (v[i] >= i+1) {
      ans = i+1;
    } else {
      break;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
  cout << fixed << setprecision(12);

  int t; cin>>t;
  while (t--) {
    cout<<solve()<<'\n';
  }
      
  

  return 0;
}
