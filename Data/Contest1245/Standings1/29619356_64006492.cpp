#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 3e6+10;
const LL mod = 1e9+7;

int n , px[2010] , py[2010] , c[2010] , k[2010] , f[2010];
LL ans;
struct mmp{
	int x , y;
	LL z;
 	bool operator < (const mmp &op) const{
 		return z < op.z;
	 }
};
vector<mmp> v;
vector<int> a1;
vector<pair<int,int> > a2;

int getf(int x)
{
	if (f[x] != x) f[x] = getf(f[x]);
	return f[x];
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n+1 ; i++)
		f[i] = i;
	for (i = 1 ; i <= n ; i++)
		scanf("%d%d",&px[i],&py[i]);
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&c[i]);
		v.push_back({i,n+1,c[i]});
	}
	for (i = 1 ; i <= n ; i++)
		scanf("%d",&k[i]);
	for (i = 1 ; i < n ; i++)
		for (j = i+1 ; j <= n ; j++)
			v.push_back({i,j,(LL)(k[i]+k[j])*(LL)(abs(px[i]-px[j])+abs(py[i]-py[j]))});
	sort(v.begin(),v.end());
	for (auto i: v)
	{
		int fx = getf(i.x);
		int fy = getf(i.y);
		if (fx != fy)
		{
			if (i.y == n+1) a1.push_back(i.x);
			else a2.push_back({i.x,i.y});
			ans += i.z;
			f[fx] = fy;
		}
	}
	cout << ans << "\n";
	sort(a1.begin(),a1.end());
	cout << (int)a1.size() << "\n";
	for (auto i: a1)
		printf("%d\n",i);
	sort(a2.begin(),a2.end());
	cout << (int)a2.size() << "\n";
	for (auto i: a2)
		printf("%d %d\n",i.first,i.second);
	return 0;
}