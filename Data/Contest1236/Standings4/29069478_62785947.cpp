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
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		int t = min(b, c / 2);
		b -= t;
		ans += t;
		t = min(a, b / 2);
		ans += t;
		cout << 3 * ans << "\n";
	}
}
