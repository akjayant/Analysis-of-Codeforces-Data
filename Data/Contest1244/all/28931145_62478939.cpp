#include <bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
using namespace std;
const int MAX = 2e5 + 5;
const ll inf = 1e18 + 7;
int n, dress[MAX], head[MAX], nex[MAX], in[MAX], to[MAX], tot;
ll res = inf;
int color[MAX], answer[MAX];
void add(int a, int b) {
	in[tot] = a, to[tot] = b;
	nex[tot] = head[in[tot]];
	head[in[tot]] = tot; ++tot;
}
int qwe[10];
int asd, q, w;
void func()
{
	asd++, asd++;
	memset(qwe, 0, sizeof(qwe));
}
void func1()
{
	asd--;
}
ll a[4][MAX];
void bianli(int in, int f, int res1, int res2, ll huafei)
{
	func(); func1(); func1();
	for (int i = 1; i <= 3; ++i) 
	{
		if (res1 == -1 && res2 == -1) 
		{
			bool jzk = false;
			color[in] = i;
			ll tem = huafei + a[i][in];
			if (jzk == true)
				func();
			for (int num = head[in]; num != -1; num = nex[num])
			{
				if (to[num] == f) 
					continue;
				jzk = true;
				bianli(to[num], in, -1, i, tem);
			}
			if (!jzk) 
			{
				if (jzk == true)
					func();
				if (tem < res) 
				{
					for (int j = 1; j <= n; ++j)
						answer[j] = color[j];
					res = tem;
				}
			}
		}
		else if (res1 == -1) 
		{
			if (i != res2) 
			{
				color[in] = i;
				ll tem = huafei + a[i][in];
				bool jzk = false;
				if (jzk == true)
					func();
				for (int num = head[in]; num != -1; num = nex[num]) 
				{
					if (to[num] == f) 
						continue;
					jzk = true;
					bianli(to[num], in, res2, i, tem);
				}
				if (!jzk) 
				{
					if (jzk == true)
						func();
					if (tem < res) 
					{
						for (int j = 1; j <= n; ++j)
							answer[j] = color[j];
						res = tem;
					}
				}
			}
		}
		else //other
		{
			if (i != res1 && i != res2) 
			{
				color[in] = i;
				ll tidai = huafei + a[i][in];
				bool jzk = false;
				if (jzk == true)
					func();
				for (int number = head[in]; number != -1; number = nex[number]) 
				{
					if (to[number] == f)
						continue;
					jzk = true;
					bianli(to[number], in, res2, i, tidai);
				}
				if (!jzk) 
				{
					if (jzk == true)
						func();
					if (tidai < res) 
					{
						for (int j = 1; j <= n; ++j)
							answer[j] = color[j];
						res = tidai;
					}
				}
			}
		}
		func1();
	}func1();
}
int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", &a[1][i]);
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", &a[2][i]);
	for (int i = 1; i <= n; ++i) 
		scanf("%lld", &a[3][i]);
	tot = 0;
	memset(head, -1, sizeof(head));
	for (int i = 1; i < n; ++i)
	{
		scanf("%d%d", &q, &w);
		add(q, w); 
		add(w, q);
		dress[q]++;
		dress[w]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (dress[i] >= 3)
		{
			puts("-1");
			return 0;
		}
	}
	int dian = 0;
	for (int i = 1; i <= n; ++i) 
		if (dress[i] == 1) 
		{ 
			dian = i;
			bianli(dian, 0, -1, -1, 0);
			break; 
		}
	//find thw first
	printf("%lld\n", res);
	for (int i = 1; i <= n; ++i) 
		printf("%d%c", answer[i], i == n ? '\n' : ' ');
}