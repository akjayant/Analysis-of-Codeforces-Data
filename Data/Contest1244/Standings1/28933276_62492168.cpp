#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main()
{
	ll n = 0, k = 0;
	cin >> n >> k;

	vector<ll> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	ll beginNum = 0, endNum = 0;
	for (; beginNum < n && arr[beginNum] == arr[0]; ++beginNum);
	for (; n - endNum - 1 >= 0 && arr[n - endNum - 1] == arr.back(); ++endNum);

	ll counter = 0, dif = arr.back() - arr[0];

	while (true)
	{
		if (beginNum + endNum > n)
		{
			cout << 0 << endl;
			return 0;
		}

		if (beginNum < endNum)
		{
			if ((arr[beginNum] - arr[beginNum - 1]) * beginNum < k)
			{
				k -= (arr[beginNum] - arr[beginNum - 1]) * beginNum;
				dif -= arr[beginNum] - arr[beginNum - 1];
				arr[beginNum - 1] = arr[beginNum];
				while(beginNum < n && arr[beginNum] == arr[beginNum - 1])
					beginNum++;
			}
			else
			{
				dif -= k / beginNum;
				break;
			}
		}
		else
		{
			if ((arr[n - endNum] - arr[n - endNum - 1]) * endNum < k)
			{
				k -= (arr[n - endNum] - arr[n - endNum - 1]) * endNum;
				dif -= arr[n - endNum] - arr[n - endNum - 1];
				arr[n - endNum] = arr[n - endNum - 1];
				while (n - endNum - 1 >= 0 && arr[n - endNum] == arr[n - endNum - 1])
					endNum++;
			}
			else
			{
				dif -= k / endNum;
				break;
			}
		}

	}

	cout << dif << endl;

	return 0;
}