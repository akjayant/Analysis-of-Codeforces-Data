#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100005
int n, now, m, A[N];
ll k;
struct node
{
	int v, p;
	bool operator < (node b)const{return v < b.v;}
};
set<node>s;
int main()
{
	scanf("%d%I64d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]);
	sort(A + 1, A + n + 1);
	now = A[n] - A[1];
	for (int i = 1; i <= n; i++)
	{
		m++;
		if (A[i] != A[i + 1])
		{
			s.insert((node){A[i], m});
			m = 0;
		}
	}
	for (; s.size() > 1; )
	{
		set<node>::iterator a = s.begin(), b = s.end();
		b--;
		if (a -> p <= b -> p)
		{
			node x = *a;
			a++;
			node y = *a;
			if ((ll)(y.v - x.v) * x.p >= k)
			{
				now -= k / x.p;
				break;
			}
			now -= y.v - x.v;
			k -= (ll)(y.v - x.v) * x.p;
			s.erase(x), s.erase(y);
			y.p += x.p;
			s.insert(y);
		}
		else
		{
			node x = *b;
			b--;
			node y = *b;
			if ((ll)(x.v - y.v) * x.p >= k)
			{
				now -= k / x.p;
				break;
			}
			now -= x.v - y.v;
			k -= (ll)(x.v - y.v) * x.p; 
			s.erase(x), s.erase(y);
			y.p += x.p;
			s.insert(y);
		}
	}
	printf("%d\n", now);
}
