#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , c[3][maxn] , d[maxn] , a[3] , p[maxn];
vector<int> v[maxn];
LL ans , ss;

void dfs(int x , int y , int z , LL s)
{
	p[x] = a[z%3]+1;
	s += c[a[z%3]][x];
	z++;
	if (z == n)
	{
		ans = min(ans,s);
		return;
	}
	for (auto to: v[x])
		if (to != y) dfs(to,x,z,s);
}

int main()
{
	int i , j , k , x , y;
	cin >> n;
	for (j = 0 ; j < 3 ; j++)
		for (i = 1 ; i <= n ; i++)
			scanf("%d",&c[j][i]);
	for (i = 1 ; i < n ; i++) 
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (i = 1 ; i <= n ; i++) 
		d[(int)v[i].size()]++;
	if (d[1] != 2 || d[2] != n-2)
	{
		cout << "-1\n";
		return 0;
	}
	for (i = 1 ; i <= n ; i++)
		if ((int)v[i].size() == 1)
		{
			ans = mod*mod;
			a[0] = 0;
			a[1] = 1;
			a[2] = 2;
			do{
				dfs(i,0,0,0);
			}while (next_permutation(a,a+3));
			ss = ans;
			ans = mod*mod;
			a[0] = 0;
			a[1] = 1;
			a[2] = 2;
			do{
				dfs(i,0,0,0);
				if (ans == ss)
				{
					cout << ans << "\n";
					for (k = 1 ; k <= n ; k++)
						printf("%d ",p[k]);
					cout << "\n";
					return 0;
				}
			}while (next_permutation(a,a+3));
		}
	return 0;
} 
