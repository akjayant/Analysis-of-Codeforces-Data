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

const int N = 1005;
int ni[N];

int main()
{
	int k;
	scanf("%d", &k);

	while (k--)
	{
		int n;
		scanf("%d", &n);
		
		for (int i = 0; i < n; ++ i) 
		{
			scanf("%d", &ni[i]);
		}

		sort(ni, ni + n);

		int ans = 1;
		for(int i = n - 1; i >= 0; -- i)
		{
			if(ni[i] < n - i)
			{
				break;
			}
			ans = n - i;
		}

		printf("%d\n", ans);
	}

	return 0;
}