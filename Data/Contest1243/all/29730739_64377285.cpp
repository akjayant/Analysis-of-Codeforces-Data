#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;



int main()
{
	int k;
	cin >> k;
	for(unsigned j = 0; j < k; j++)
	{
		int n;
		cin >> n;
		int a[n];
		for(unsigned i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		reverse(a, a + n);
		for(int i = 0; i < n; i++)
		{
			if(a[i] <= i + 1)
			{
				cout << max(a[i], i) << endl;
				break;
			}
		}
	}
	return 0;
}