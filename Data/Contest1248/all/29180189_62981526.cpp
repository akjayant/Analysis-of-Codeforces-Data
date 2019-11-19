#include <iostream>
#include <cstdio>

using namespace std;
const int N = 100005;
int T, n, m, p[N], q[N];
long long j1, o1, j2, o2;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		j1 = o1 = j2 = o2 = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
			if(p[i] & 1) j1++;
			else o1++;
		}
		scanf("%d", &m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &q[i]);
			if(q[i] & 1) j2++;
			else o2++;
		}
		cout << (j1*j2 + o1*o2) << endl;
	}
	return 0;
}