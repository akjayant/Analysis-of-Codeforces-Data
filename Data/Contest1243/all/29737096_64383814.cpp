// In The Name Of GOD
#include<bits/stdc++.h>

using namespace std;

#define int long long 

int n, x;
vector<int> vec;

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cerr << "HELLO WORLD:)\n";
	cin >> n;
	for (int i = 2; i * i <= n; ++i)
		if (!(n % i)) {
			vec.push_back(i);
			while (!(n % i))
				n /= i;
		}
	if (n != 1)
		vec.push_back(n);
	if (vec.size() == 1)
		return cout << vec.back() << '\n', false;
	return cout << "1\n", false;
}