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
  int t;
  std::cin >> t;
  for(int q=0;q<t;q++){
    int a, b, c, d, k;
    std::cin >> a >> b >> c >> d >> k;
    int x = a/c + (a%c==0?0:1);
    int y = b/d + (b%d==0?0:1);
    if(x+y<=k) std::cout << x << " " << y << '\n';
    else std::cout << -1 << '\n';
  }
  return 0;
}
