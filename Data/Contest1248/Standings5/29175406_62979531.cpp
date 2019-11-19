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
		int N;
		cin >> N;
		long long cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= N; i++)
		{
			int t;
			cin >> t;
			if (t & 1)
				cnt0++;
			else
				cnt1++;
		}
		int M;
		cin >> M;
		for (int i = 1; i <= M; i++)
		{
			int t;
			cin >> t;
			if (t & 1)
				cnt2++;
			else
				cnt3++;
		}
		cout << cnt0 * cnt2 + cnt1 * cnt3 << "\n";
	}
}
