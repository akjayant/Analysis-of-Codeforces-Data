#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>    
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <bitset>
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef unsigned long long ull; 
typedef vector<int> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const int M = 1e9 + 7;
//__int128


signed main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  while(T--){
  	int a, b, c;
  	cin >> a >> b >> c;
  	int res = 0;
  	for(int i = 0; i <= a; ++i) {
  		for(int j = 0; j <= b; ++j) {
  			if(a - i >= 0 && b - 2 * i - j >= 0 && c - 2 * j >= 0) {
  				res = max(3 * i + 3 * j, res);
  			}
  		}
  	}
  	cout << res << endl;
  }
	return 0;
}