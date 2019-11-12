#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))
#define mp make_pair

typedef unsigned long long ll;

const int N = 60;
int n, T;
int d[N], g[N];
char st[N];
int sl[N << 1], sr[N << 1], s;

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
		read(n); s = 0;
		scanf("%s", st);
		for (int i = 0; i < n; ++i) d[i + 1] = st[i] - 'a' + 1;
		scanf("%s", st);
		for (int i = 0; i < n; ++i) g[i + 1] = st[i] - 'a' + 1;
		for (int i = 1; i <= n; ++i)
		{
			if (d[i] == g[i]) continue;
			bool fl = 0;
			for (int j = i + 1; j <= n; ++j)
				if (d[j] == d[i])
				{
					swap(d[j], g[i]);
					++s; sl[s] = j; sr[s] = i;
					fl = 1;
					break;
				}
			if (!fl)
			{
				for (int j = i + 1; j <= n; ++j)
					if (g[j] == d[i])
					{
						swap(g[j], d[n]);
						swap(d[n], g[i]);
						++s; sl[s] = n; sr[s] = j;
						++s; sl[s] = n; sr[s] = i;
						fl = 1;
						break;
					}
			}
			if (!fl)
			{
				s = -1; break;
			}
		}
		if (s == -1) printf("No\n"); else
		{
			printf("Yes\n");
			if (s == 0) ++s, sl[1] = sr[1] = 1;
			printf("%d\n", s);
			for (int i = 1; i <= s; ++i) printf("%d %d\n", sl[i], sr[i]);
		}
	}
	return 0;
}