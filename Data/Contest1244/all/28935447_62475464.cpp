#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> >
#define vl vector<ll>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(int argc, char const *argv[]) {
  int Q;
  std::cin >> Q;
  for(int q=0;q<Q;q++){
    int n;
    int ans = 0;
    std::cin >> n;
    string s;
    std::cin >> s;
    int l=10000000, r =-1;
    for(int i=0;i<n;i++){
      if(s[i]=='1'){
        l = min(l, i);
        r = max(r, i);
      }
    }
    if(r==-1){
      std::cout << n << '\n';
      continue;
    }
    int loss = 0;
    for(int i=l;i<=r;i++) if(s[i]!='1') loss++;
    ans = max({2*n-2*l, 2*n-2*(n-r-1), 2*n-l-(n-r-1)-loss});
    std::cout << ans << '\n';
  }
  return 0;
}
