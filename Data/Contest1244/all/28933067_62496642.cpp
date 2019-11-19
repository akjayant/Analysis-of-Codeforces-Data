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
const int maxn = 1e5 + 10;
int arr[maxn];
int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	long long K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	sort(arr + 1, arr + N + 1);
	int p1=1, p2=N;
	for (int i = 2; i <= N; i++)
	{
		if (arr[i] != arr[i - 1])
			break;
		p1++;
	}
	for (int i = N - 1; i >= 1; i--)
	{
		if (arr[i] != arr[i + 1])
			break;
		p2--;
	}
	bool judge = false;
	while (K && arr[p1] != arr[p2])
	{
		int len1 = p1, len2 = N - p2 + 1;
		if (len1 < len2)
		{
			long long delta = arr[p1 + 1] - arr[p1];
			if (K / len1 < delta)
			{
				cout << arr[p2] - arr[p1] - K / len1;
				judge = true;
				break;
			}
			K -= delta * len1;
			p1++;
			while (arr[p1] == arr[p1 + 1])
			{
				p1++;
			}
			continue;
		}
		if (len2 <= len1)
		{
			long long delta = arr[p2] - arr[p2-1];
			if (K / len2 < delta)
			{
				judge = true;
				cout << arr[p2] - arr[p1] - K / len2;
				break;
			}
			K -= delta * len2;
			p2--;
			while (arr[p2] == arr[p2 - 1])
			{
				p2--;
			}
			continue;
		}
	}
	if (!judge)
		cout << arr[p2] - arr[p1];
}
