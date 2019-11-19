#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 1000000007
#define int long long
#define ll long long
#define EPS 0.00000000000001
#define ld long double
#define inf 1000000000000000
#define N 100005


int32_t main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("int.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    int n;
    cin >> n;
    vector<int> g[n + 1];
    vector<int> color[3];
    for(int i = 0;i <= 2;i++)
    	color[i].resize(n + 1);
    for(int j = 0;j <= 2;j++)
    {
    	for(int i = 1;i <= n;i++)
    		cin >> color[j][i];
    }
    bool ch = 1;
    for(int i = 0;i < n - 1;i++)
    {
    	int a,b;
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    	if(g[a].size() > 2)
    		ch = 0;
    	if(g[b].size() > 2)
    		ch = 0;
    }
    int start = 1;
    for(int i = 1;i <= n;i++)
    	if(g[i].size() == 1)
    		start = i;
    if(ch)
    {
    	int ans = inf;
    	vector<int> fans(n + 1);
    	vector<int> curans(n + 1);
    	for(int j = 0;j <= 2;j++)
    	{
    		int lans = 0;
    		int s = start;
    		int p = start;
    		int c = j;
    		while(1)
    		{
    			lans += color[c][s];
    			curans[s] = c;
    			int node = -1;
    			for(auto it : g[s])
    			{
    				if(it != p)
    				{
    					node = it;
    					break;
    				}
    			}
    			//cerr << s << " " << p << endl;
    			if(node == -1)
    				break;
    			p = s;
    			s = node;
    			c = (c + 1) % 3;
    		}
			if(ans > lans)
			{
				ans = lans;
				fans = curans;
			}
			lans = 0;
			s = start;
			p = start;
			c = j;
    		while(1)
    		{
    			lans += color[c][s];
    			curans[s] = c;
    			int node = -1;
    			for(auto it : g[s])
    			{
    				if(it != p)
    				{
    					node = it;
    					break;
    				}
    			}
    			//cerr << s << " " << p << endl;
    			if(node == -1)
    				break;
    			p = s;
    			s = node;
    			c = (c - 1 + 3) % 3;
    		}
			if(ans > lans)
			{
				ans = lans;
				fans = curans;
			}
    	}
    	cout << ans << endl;;
    	for(int i = 1;i <= n;i++)
    		cout << fans[i] + 1 << " " ;
    }
    else
    	cout << -1;
    return 0;
}
 
 