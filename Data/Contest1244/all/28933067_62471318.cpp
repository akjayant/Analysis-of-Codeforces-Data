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
		int pos1 = INT_MAX;
		int pos2 = INT_MIN;
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			char c;
			cin >> c;
			if (c == '1')
			{
				pos1 = min(pos1, i);
				pos2 = max(pos2, i);
			}
		}
		if (pos1 == INT_MAX)
		{
			cout << N << "\n";
			continue;
		}
		cout << max(pos2 * 2, (N - pos1 + 1) * 2) << "\n";
	}
}
