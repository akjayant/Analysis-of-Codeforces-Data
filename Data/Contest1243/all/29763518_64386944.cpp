#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))
#define mp make_pair

typedef unsigned long long ll;

const int N = 10010;
int s[30];
int n,T;
char s1[N],s2[N];

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
		scanf("%s", s1);
		scanf("%s", s2);
		int a = 0, b = 0, f = 0;
		for (int i = 0; i < n; ++i)
			if (s1[i] != s2[i])
			{
				if (!a) a = i; else b = i;
				++f;
			}
		if (f == 0 || (f == 2 && s1[a] == s1[b] && s2[a] == s2[b])) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}