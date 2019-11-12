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

template <typename T>
T qpow(T a, T p, T n){
	T res = 1;
	for(; p; a = a * a % n, p >>= 1) {
		if(p & 1) {
			res = res * a % n;
		}
	}
	return res;
}
template <typename T>
inline T inv(T a, T n){
	return qpow(a, n - 2, n);
}

signed main()
{
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  int x = (qpow(2ll, m, M) - 1 + M) % M;
  cout << qpow(x, n, M) << endl;
	return 0;
}