#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<climits>
#include<cmath>
#include<map>
#include<set>
#include<deque>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		if ((a - 1) / c + 1 + (b - 1) / d + 1 <= k)
		{
			cout << (a - 1) / c + 1 << " " << (b - 1) / d + 1 << "\n";
		}
		else
			cout << -1 << "\n";
	}
}
