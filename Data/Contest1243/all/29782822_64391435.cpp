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
char a[N], b[N];

int main()
{
	int k;
	scanf("%d", &k);

	while (k--)
	{
		int n;
		scanf("%d", &n);
		scanf("%s%s", a, b);

		vector<int> ans;
		for(int i = 0; i < n; ++ i)
		{
			if(a[i] != b[i])
			{
				ans.push_back(i);
			}
		}
		if(ans.size() == 0 || ans.size() == 2 && a[ans[0]] == a[ans[1]] && b[ans[0]] == b[ans[1]])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}