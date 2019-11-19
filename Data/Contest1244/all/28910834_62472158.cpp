#include <bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
const int N = 1e3+10;
const int M = 20;
#define lowbit(x) (x&(-x))
const int inf = 0x3f3f3f3f;
const ll INF = 100000000000000000;
const int mod = 998244353;
typedef pair<int, int> P;
#define eps 1e-6
int n, m;
char s[N];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%d", &n);
		scanf("%s", s + 1);
		int MN = 1e5, MX = 0;
		for (int i = 1; i <= n; i++){
			if (s[i] == '1') MN = min(MN, i),MX=max(MX,i);
		}
		if (!MX){
			printf("%d\n", n);
			continue;
		}
		int ans = MX+max(n-MX+1,MX);
		MN = n - MN + 1;
		ans = max(ans, MN + max(n - MN + 1, MN ));
		printf("%d\n", ans);
	}
	
	return 0;
}
/*

*/