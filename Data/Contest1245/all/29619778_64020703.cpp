#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4002;
int n,xx[N],yy[N],c[N],k[N];
bool b[N];
int mabs(int x)
{	
	return x > 0 ? x : -x;
}
int calc(int x,int y)
{
	if(x > n || y > n)
		return c[min(x,y)];
//	cerr << "calc: " << x << " " << y << " " << (k[x] + k[y]) * mabs(xx[x] - xx[y]) * mabs(yy[x] - yy[y]) << endl;
	return (k[x] + k[y]) * (mabs(xx[x] - xx[y]) + mabs(yy[x] - yy[y]));
}
vector <int> ans1;
vector <pair<int,int> > ans2;
void shu()
{
	int cnt = 1,ret = 0;
	priority_queue <pair <int,pair<int,int> > > q;
	for(int i = 2;i <= n + 1;i++)
		q.push(make_pair(-calc(1,i),make_pair(1,i)));
	while(cnt < n + 1)
	{
		int cost = -q.top().first, to = q.top().second.second, from = q.top().second.first;
		q.pop();
		if(b[to])
			continue;
		b[to] = true,cnt++;
		if(max(from,to) == n + 1)
			ans1.push_back(min(from,to));
		else
			ans2.push_back(make_pair(min(from,to),max(from,to)));
		for(int i = 2;i <= n + 1;i++)
			if(!b[i])
				q.push(make_pair(-calc(to,i),make_pair(to,i)));
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> xx[i] >> yy[i];
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	for(int i = 1;i <= n;i++)
		cin >> k[i];
	shu();
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	int ans = 0;
	for(int i = 0;i < ans1.size();i++)
		ans += c[ans1[i]];
	for(int i = 0;i < ans2.size();i++)
		ans += calc(ans2[i].first,ans2[i].second);
	cout << ans << endl;
	
	cout << ans1.size() << endl;
	for(int i = 0;i < ans1.size();i++)
		cout << ans1[i] << " ";
	cout << endl << ans2.size() << endl;
	for(int i = 0;i < ans2.size();i++)
		cout << ans2[i].first << " " << ans2[i].second << endl;
	return 0;
}