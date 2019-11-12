#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;

int a[301][301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i += 2)
	{
		for (int j = 0; j < n; ++j)
			a[j][i] = i * n + j + 1;
	}
	for (int i = 1; i < n; i += 2)
	{
		for (int j = 0; j < n; ++j)
			a[j][i] = i * n + n - j;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << a[i][j] << ' ';
		cout << '\n';
	}

	char I;
	cin >> I;
}