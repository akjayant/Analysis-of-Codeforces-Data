#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		ans += min(c / 2, b) * 3;
		b -= min(b, c / 2);
		ans += min(b / 2, a) * 3;
		cout << ans << '\n';
	}


	char I;
	cin >> I;
}