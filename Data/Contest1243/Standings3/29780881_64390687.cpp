// C. Tile Painting
#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, int> > factorize(long long n)
{
	vector<pair<long long, int> > a;
	for (long long i = 2, c; i * i <= n; i += i % 2 + 1) {
		for (c = 0; n % i == 0; n /= i) c++;
		if (c > 0) a.push_back(make_pair(i, (int) c));
	}
	if (n > 1) a.push_back(make_pair(n, 1));
	return a;
}

int main(int argc, char *argv[])
{
	long long n;
	cin >> n;
	vector<pair<long long, int> > a = factorize(n);
	if (a.size() == 1) {
		cout << a[0].first << endl;
	} else {
		cout << 1 << endl;
	}

	return 0;
}
