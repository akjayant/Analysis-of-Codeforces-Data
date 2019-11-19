#include <iostream> 
#include <algorithm>  
#include <vector>
#include <stdio.h>
#include <string>
#include <map>
#include <numeric>
#include <stack>
#include <set>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;

const int N = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector <long long> fib(max(n,m) + 1);
	fib[0] = 1; fib[1] = 1;
	for (int i = 2; i <= max(m, n); i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (i > 30) fib[i] %= N;
	}
	cout << 2 * (fib[n] + fib[m] - 1) % N;

	return 0;
}