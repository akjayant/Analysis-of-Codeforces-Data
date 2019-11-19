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
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = 0;
		int y = 0;
		x = (a-1) / c + 1;
		y = (b-1) / d + 1;
		if ((x + y) > k) {
			cout << "-1" << endl;
			continue;
		}
		else {
			cout << x << " " << y << endl;
		}
	}


	return 0;
}