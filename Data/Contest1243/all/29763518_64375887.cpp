#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))
#define mp make_pair

typedef unsigned long long ll;

const int N = 1050;
int T,n;
int d[N];

void read(int& x)
{
	x = 0; bool fl = 0; char ch = getchar();
	while (!(ch >= '0' && ch <= '9')) fl |= (ch == '-'), ch = getchar();
	while ((ch >= '0' && ch <= '9')) x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	if (fl) x = -x;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);
		for (int i = 1; i <= n; ++i) read(d[i]);
		int ans = 1;
		for (int i = 1; i <= n; ++i)
		{
			int yu = 0;
			for (int j = 1; j <= n; ++j) yu += (d[j] >= i);
			ans = imax(ans, imin(i, yu));
		}
		printf("%d\n", ans);
	}
	return 0;
}