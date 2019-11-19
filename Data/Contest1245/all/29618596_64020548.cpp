#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 20000
using namespace std;
struct dl{
	long long cost;
	int u, v;
};
struct cmp{
	bool operator() (dl a, dl b)
	{
		return a.cost > b.cost;
	}
};
long long cp;
int n,x[N],y[N],c[N],d[N];
vector<int>kq1;
vector<dl>kq2;
int dd[N];
priority_queue <dl,vector<dl>,cmp> q;
void them(int u)
{
	for (int i = 1; i <= n;i++)
	if (i != u)
	{
		long long cpp = (abs(x[i] - x[u]) + abs(y[i] - y[u]));
		cpp = cpp*(d[i] + d[u]);
		dl tmp = { cpp, i, u };
		q.push(tmp);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
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
		while (1)
		{
			dl tmp = q.top();
			q.pop();
			if (tmp.u == tmp.v)
			{
				if (dd[tmp.u] == 0)
				{
					them(tmp.u);
					dd[tmp.u] = 1;
					kq1.push_back(tmp.u);
					cp += tmp.cost;
					break;
				}
			}
			else
			{
				if (dd[tmp.u] + dd[tmp.v] == 1)
				{
					if (dd[tmp.u] == 0) them(tmp.u);
					else them(tmp.v);
					dd[tmp.u] = 1;
					dd[tmp.v] = 1;
					kq2.push_back(tmp);
					cp += tmp.cost;
					break;
				}
			}
		}
	}
	sort(kq1.begin(), kq1.end());
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
	return 0;
}