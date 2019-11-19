#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const ll inf = 1000000000000000000;
ll n, a[5][100005], x, y, start, ans[10], poryad[10][10], mun = inf, muni = 1, viv[100005];
vector<ll> edges[100005];
void obhod(ll v, ll pr, ll num)
{
	for (int i = 0; i < (ll)edges[v].size(); i ++)
		if (edges[v][i] != pr)
		{
			for (int j = 1; j <= 6; j ++)
				ans[j] += a[poryad[j][num % 3]][v];
			//for (int j = 1; j <= 6; j ++)
			//	cout << ans[j] << " ";
			//cout << endl;
			pr = v;
			obhod(edges[v][i], pr, num + 1);
			return;
		}
	for (int j = 1; j <= 6; j ++)
		ans[j] += a[poryad[j][num % 3]][v];
}
void getans(ll v, ll pr, ll muni, ll num)
{
	for (int i = 0; i < (ll)edges[v].size(); i ++)
		if (edges[v][i] != pr)
		{
			viv[v] = poryad[muni][num % 3];
			pr = v;
			getans(edges[v][i], pr, muni, num + 1);
			return;
		}
	viv[v] = poryad[muni][num % 3];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[1][i];
	for (int i = 1; i <= n; i ++)
		cin >> a[2][i];
	for (int i = 1; i <= n; i ++)
		cin >> a[3][i];
	for (int i = 1; i < n; i ++)
	{
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
		if ((ll)edges[x].size() > 2)
		{
			cout << -1;
			return 0;
		}
		if ((ll)edges[y].size() > 2)
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 1; i <= n; i ++)
		if ((ll)edges[i].size() == 1)
			start = (ll)i;
	poryad[1][0] = 1;
	poryad[1][1] = 2;
	poryad[1][2] = 3;
	
	poryad[2][0] = 2;
	poryad[2][1] = 1;
	poryad[2][2] = 3;
	
	poryad[3][0] = 3;
	poryad[3][1] = 1;
	poryad[3][2] = 2;
	
	poryad[4][0] = 1;
	poryad[4][1] = 3;
	poryad[4][2] = 2;
	
	poryad[5][0] = 3;
	poryad[5][1] = 2;
	poryad[5][2] = 1;
	
	poryad[6][0] = 2;
	poryad[6][1] = 3;
	poryad[6][2] = 1;
	
	obhod(start, -1, 0);
	for (int i = 1; i <= 6; i ++)
		if (ans[i] < mun)
		{
			mun = ans[i];
			muni = i;
		}
	cout << mun << endl;
	getans(start, -1, muni, 0);
	for (int i = 1; i <= n; i ++)
		cout << viv[i] << " ";
	return 0;
}