#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll old[(ll)(300000+50)];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
    	ll n;
    	cin >> n;
    	string a,b;
    	cin >> a >> b;
    	vector <ll> ind;
    	for(ll i = 0;i < n;i++)
    	{
    		if(a[i] != b[i])
    		{
    			old[a[i] - '0']++;
    			old[b[i] - '0']++;
    			ind.push_back(i);
			}
		}
		int g = 0;
		for(ll i = 0;i < 30;i++)
		{
			if(old[i] % 2)
			{
				g = 1;
				cout << "No" << endl;
				break;
			}
		}
		if(g==1)
        continue;
		
		vector <pair <ll,ll>> op;
		int d = 0;
		for(ll i = 0;i < (ll)ind.size();i++)
		{
			if(a[ind[i]] == b[ind[i]])continue;
			g = 0;
			for(ll j = i + 1;j < (ll)ind.size();j++)
			{
				if(b[ind[i]] == b[ind[j]])
				{
					op.push_back(make_pair(ind[i],ind[j]));
					swap(a[ind[i]],b[ind[j]]);
					g = 1;
					break;
				}
			}
			if(g==1)
            continue;
			for(ll j = i + 1;j < (ll)ind.size();j++)
			{
				if(b[ind[i]] == a[ind[j]])
				{
					op.push_back(make_pair(ind[j],ind[j]));
					swap(a[ind[j]],b[ind[j]]);
					op.push_back(make_pair(ind[i],ind[j]));
					swap(a[ind[i]],b[ind[j]]);
					g = 1;
					break;
				}
			}
			if(g == 0)
			{
				d = 1;
				cout << "No" << endl;
				break;
			}
		}
		if(d==1)
        continue;
		cout << "Yes" << endl;
		cout << (ll)op.size() << endl;
        ll i=0;
		while(i < op.size())
		{
			cout << op[i].first + 1 << " " << op[i].second + 1 << endl;
            i++;
		}
	}
  return 0;
}