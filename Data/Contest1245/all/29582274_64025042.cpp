#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 100000
using namespace std;
struct dl{
	long long chiphi;
	int u, v;
};
struct cmp{
	bool operator() (dl a, dl b)
	{
		return a.chiphi > b.chiphi;
	}
};
long long cp;
int n, a[N], b[N], c[N], d[N];
vector<int>kq1;
vector<dl>kq2;
int dd[N];
priority_queue <dl, vector<dl>, cmp> q;
void them(int u)
{
	for (int i = 1; i <= n; i++)
	if (i != u)
	{
		long long gt = (abs(a[i] - a[u]) + abs(b[i] - b[u]));
		gt = gt*(d[i] + d[u]);
		dl tmp = { gt, i, u };
		q.push(tmp);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
	{
		dl tmp = { c[i], i, i };
		q.push(tmp);
	}
	for (int i = 1; i <= n; i++)
	{
		while (true)
		{
			dl tmp = q.top();
			q.pop();
			if (tmp.u != tmp.v)
			{
				if (dd[tmp.u] + dd[tmp.v] == 1)
				{
					if (dd[tmp.u] == 0) them(tmp.u);
					else them(tmp.v);
					dd[tmp.u] = 1;
					dd[tmp.v] = 1;
					kq2.push_back(tmp);
					cp += tmp.chiphi;
					break;
				}
			}
			else
			{
				if (dd[tmp.u] == 0)
				{
					them(tmp.u);
					dd[tmp.u] = 1;
					kq1.push_back(tmp.u);
					cp += tmp.chiphi;
					break;
				}
			}
		}
	}
	cout << cp << endl;
	cout << kq1.size();
	cout << endl;
	for (int i = 0; i < kq1.size(); i++)
		cout << kq1[i] << " ";
	cout << endl;
	cout << kq2.size();
	cout << endl;
	for (int i = 0; i < kq2.size(); i++)
		cout << kq2[i].u << " " << kq2[i].v << endl;
}