#include <iostream>
#include <iomanip>
#include <stack>
#define ll long long
#define ui unsigned int
using namespace std;
const int INF = 1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, ans, a, b, c;
	cin >> t;
	for (int i=0; i<t; i++)
	{
		cin >> a >> b >> c;
		ans = min(b, c / 2);
		b -= ans;
		cout << ans * 3 + min(a, b/2) * 3 << "\n";
	}
	return 0;
}