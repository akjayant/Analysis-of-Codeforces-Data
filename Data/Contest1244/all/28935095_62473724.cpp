#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define Maxi 1005
typedef long long ll;
char str[Maxi];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d%s", &n, str);
		int ans = n;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '1')
			{
				ans = max(ans, 2*(i + 1));
				ans = max(ans, 2*(n - i));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}