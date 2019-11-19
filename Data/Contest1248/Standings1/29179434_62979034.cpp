#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <array>
#include <memory.h>
#include <memory>

using namespace std;

int main()
{
	int it = 0;
	cin >> it;

	for(int it1 = 0; it1<it; it1++)
	{
		long long n, m, a, na = 0, ma = 0;
		cin >> n;

		for(int i = 0; i<n; i++)
		{
			cin >> a;
			if(a&1) na++;
		}

		cin >> m;
		for(int i = 0; i<m; i++)
		{
			cin >> a;
			if(a&1) ma++;
		}

		cout << na*ma+(n-na)*(m-ma) << endl;
	}

	return 0;
}