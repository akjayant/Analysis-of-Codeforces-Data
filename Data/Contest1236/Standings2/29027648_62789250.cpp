#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;

long long BinPow(long long a, int p)
{
	if (p == 0) return 1;
	if (p % 2) return ((a * BinPow(a, p - 1)) % mod);
	return BinPow((a * a) % mod, p / 2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	cout << BinPow((BinPow(2, m) - 1 + mod) % mod, n) << endl;;

	char I;
	cin >> I;
}