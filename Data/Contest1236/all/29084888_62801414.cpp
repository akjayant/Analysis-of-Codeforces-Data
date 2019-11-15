#include <iostream>
#include <iomanip>
#include <stack>
#define ll long long
#define ui unsigned int
using namespace std;
const int INF = 1e9;
const ll mod = (1e9) + 7;
int ans[301][301];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i += 2)
		for (int j = 0; j < n; j++)
			ans[j][i] = i * n + j + 1;
	for (int i = 1; i < n; i += 2)
		for (int j = n - 1; j >= 0; j--)
			ans[j][i] = i * n + n - j;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}
	return 0;
}