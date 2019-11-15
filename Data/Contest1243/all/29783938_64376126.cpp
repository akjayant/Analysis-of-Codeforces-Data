#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int k;
	cin >> k;
	for (; k > 0; k--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		int counter = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (counter + 1 <= a[i])
			{
				counter++;
			}
			else
			{
				break;
			}
		}
		cout << counter << "\n";
	}
}