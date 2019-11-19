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
    int k;
    cin >> k;
    map<int,int> m;
    for(int i = 0;i < n;i++)
    {
    	int a;
    	cin >> a;
    	m[a]++;
    }
    vector<pair<int,int>> v;
    for(auto& it : m)
    {
    	v.push_back({it.first,it.second});
    }
    if(v.size() == 1)
    {
    	cout << 0;
    	return 0;
    }
    int l = 0;
    int r = (int)(v.size()) - 1;
    while(k and l < r)
    {
    	int m1 = v[l].second;
    	int m2 = v[r].second;
    	if(m2 < m1)
    	{
    		int mvs = v[r].first - v[r - 1].first;
    		if(mvs * v[r].second <= k)
    		{
    			k -= mvs * v[r].second;
    			v[r -1].second += v[r].second;
    			r--;
    		}
    		else
    		{
    			int z = k / v[r].second;
    			v[r].first -= z;
    			break;
    		}
    	}
    	else
    	{
    		int mvs = v[l + 1].first - v[l].first;
    		if(mvs * v[l].second <= k)
    		{
    			k -= mvs * v[l].second;
    			v[l + 1].second += v[l].second;
    			l++;
    		}
    		else
    		{
    			int z = k / v[l].second;
    			v[l].first += z;
    			break;
    		}
    	}
    }
    cout << v[r].first - v[l].first;
    return 0;
}
 
 