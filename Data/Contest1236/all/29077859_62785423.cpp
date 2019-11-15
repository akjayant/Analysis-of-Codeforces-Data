#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define nmax_def 110000
#define Cmax_def 2200
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	int N;
	cin >> N;
	rep(i, N) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		int bc = c / 2;
		bc = min(bc, b);
		b -= bc;
		int ab = b / 2;
		ab = min(ab, a);
		ans = ab + bc;
		ans *= 3;
		cout << ans << endl;
	}


	return 0;
}