#include <bits/stdc++.h>
using namespace std;

long long c[4][100005];
vector <int> t[100005];
bool u[100005];
int gd[100005];

int c1c[4];
long long r;
vector <pair <long long, vector <int> > > res;

void dfs(int v, int g)
{
	r += c[c1c[g]][v];
	gd[v] = c1c[g];
	
	for(int i: t[v])
	{
		if(!u[i])
		{
			u[i] = 1;
			dfs(i, (g+1) % 3);
		}
	}
}


int main()
{
	int n;
	cin >> n;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> c[i][j];
		}
	}
	
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		
		t[a].push_back(b);
		t[b].push_back(a);
	}
	
	int u1;
	
	for(int i = 0; i < n; i++)
	{
		if(t[i].size() >= 3)
		{
			cout << -1;
			return 0;
		}
		else if(t[i].size() == 1) u1 = i;
	}
	
	long long mr = 1000000000000000;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(i == j) continue;
			for(int k = 0; k < 3; k++)
			{
				if(k == i || k == j) continue;
				
				for(int e = 0; e < n; e++)
				{
					u[e] = 0;
					gd[e] = 0;
				}
				u[u1] = 1;
				
				c1c[0] = i;
				c1c[1] = j;
				c1c[2] = k;
				
				r = 0;
				
				dfs(u1, 0);
				
				vector <int> cc;
				
				for(int e = 0; e < n; e++)
				{
					cc.push_back(gd[e] + 1);
				}
				mr = min(mr, r);
				res.push_back(make_pair(r, cc));
			}
		}
	}
	
	for(pair <long long, vector<int> > i: res)
	{
		if(i.first == mr)
		{
			cout << mr << endl;
			for(int j: i.second) cout << j << " ";
			
			return 0;
		}
	}
	
	return 0;
}