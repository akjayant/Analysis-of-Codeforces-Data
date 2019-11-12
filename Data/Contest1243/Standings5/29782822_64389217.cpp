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

const int N = 55;
char a[N], b[N];
int num[N];

int main()
{
	int k;
	scanf("%d", &k);

	while (k--)
	{
		fill(num, num + N, 0);
		int n;
		scanf("%d", &n);
		scanf("%s%s", a, b);

		for(int i = 0; i < n; ++ i)
		{
			++num[a[i] - 'a'];
			++num[b[i] - 'a'];
		}

		bool flag = false;
		for(int i = 0; i < N; ++ i)
		{
			if(num[i] % 2)
			{
				flag = true;
				break;
			}
		}

		if(flag)
		{
			printf("No\n");
			continue;
		}

		vector<pair<int, int>> ans;
		for (int i = 0; i < n; ++i)
		{
			if(a[i] != b[i])
			{
				bool f = false;
				int index = 0;
				for(int j = i + 1; j < n; ++ j)
				{
					if(a[j] == a[i])
					{
						index = j;
						f = false;
					}
					else if(b[j] == a[i])
					{
						index = j;
						f = true;
					}
				}
				if(f)
				{
					swap(a[i + 1], b[index]);
					swap(a[i + 1], b[i]);
					ans.push_back(make_pair(i + 1, index));
					ans.push_back(make_pair(i + 1, i));
				}
				else
				{
					swap(a[index], b[i]);
					ans.push_back(make_pair(index, i));
				}
			}
		}

		printf("Yes\n");
		if (ans.size() == 0)
		{
			printf("1\n");
			printf("1 1\n");
		}
		else
		{
			printf("%d\n", ans.size());
			for (const auto &p : ans)
			{
				printf("%d %d\n", p.first + 1, p.second + 1);
			}
		}
	}

	return 0;
}