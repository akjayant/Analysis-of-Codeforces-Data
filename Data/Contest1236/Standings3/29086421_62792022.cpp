#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

long long mod = 1e9 + 7;

long long binpow(long long a, long long n) {
	long long res = 1;
	while (n) {
		if (n & 1) {
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		n >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	long long n, m;
	cin >> n >> m;
	cout << binpow(binpow(2, m) - 1, n) << endl;
	return  0;
}
