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
		rep(j, N) {
			int sum = j * N;
			if (j % 2 == 0) {
				sum += (i + 1);
			}
			else {
				sum += (N - i);
			}
			cout << sum << " ";
		}
		cout << endl;
	}


	return 0;
}