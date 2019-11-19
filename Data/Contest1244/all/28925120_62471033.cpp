#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctype.h>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<iterator>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define INF 0x3f3f3f3f
#define eps 1e-8

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int maxn = 1020;
const int mod = 998244353;
char str[maxn];

int main()
{
	int t, n, i, j, ans, num;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %s", &n, str);
		ans = n, num = 0;
		for(i=0;i<n;i++)
		{
			num += str[i]-'0';
			if(str[i] == '0')continue;
			ans = max(ans, (i+1)*2);
			ans = max(ans, (n-i)*2);
		}
		ans = max(ans, n+num);
		printf("%d\n", ans);
	}
	return 0;
}
