#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
//__int128


signed main() {
  // freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.setf(ios::fixed); cout.precision(10);
  int T;
  cin >> T;
  while(T--){
    int a, b;
    cin >> a >> b;
    if(__gcd(a, b) == 1) {
      cout << "Finite" << endl;
    } else {
      cout << "Infinite" << endl;
    }
  }
  return 0;
}