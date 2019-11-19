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
		int n;
		string S;
		cin >> n;
		cin >> S;
		int ans = 0;
		rep(j, n) {
			if (S[j] == '1') {
				ans = max(ans, (j + 1));
				ans = max(ans, (n - j));
			}
		}
		ans *= 2;
		ans = max(ans, n);
		cout << ans << endl;
	}
	return 0;
}