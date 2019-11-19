#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <cmath>
#include <string>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

const int N = 10005;
long long gcd(long long a, long long b)
{
	while (b)
	{
		long long c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int main()
{
	//for(long long i = 1; i <= 1000000000000; ++ i)
	{
		//cout << i << endl;
		long long n;
		cin >> n;
		if (n == 1)
		{
			printf("1\n");
			return 0;
		}

		vector<long long> v;
		for (long long i = 2; i * i <= n; ++i)
		{
			while (n % i == 0)
			{
				n /= i;
				v.push_back(i);
			}
		}
		if (n > 1)
		{
			v.push_back(n);
		}

		if (v.size() == 1)
		{
			cout << v[0] << endl;
		}
		else
		{
			long long ans = gcd(v[0], v[1]);
			for (int i = 2; i < v.size(); ++i)
			{
				ans = gcd(ans, v[i]);
			}
			cout << ans << endl;
		}

	}
	return 0;
}