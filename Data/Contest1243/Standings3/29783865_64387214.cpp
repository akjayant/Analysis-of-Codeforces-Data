#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
using namespace std;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define int long long
using pii = pair<int, int>;

ifstream in("in.in");

const int INF = 1e9;

void speed_up() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int get_div(int n) {
	vector<int> res;
	int i = 2;
	while (n % i != 0 && i * i <= n) {
		i++;
	}
	if (n % i != 0) {
		return n;
	}
	while (n % i == 0) {
		n /= i;
	}
	if (n == 1) {
		return i;
	} else {
		return -1;
	}
}

signed main() {
	speed_up();
	int n;
	cin >> n;
	int d = get_div(n);
	if (d == -1) {
		cout << "1\n";
	} else {
		cout << d << "\n";
	}
	return 0;
}