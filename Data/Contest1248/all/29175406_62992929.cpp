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
	cin >> N;
	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr + 1, arr + N + 1);
	long long ans = 0;
	for (int i = 1; i <= N / 2; i++)
	{
		ans += arr[i + N / 2];
	}
	if (N & 1)
		ans += arr[N];
	cout << ans * ans + (sum - ans) * (sum - ans);

}
