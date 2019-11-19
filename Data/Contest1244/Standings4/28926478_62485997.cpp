#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll c[n][3];
    for(ll i=0;i<n;i++)
    	cin>>c[i][0];
    for(ll i=0;i<n;i++)
    	cin>>c[i][1];
    for(ll i=0;i<n;i++)
    	cin>>c[i][2];
    vector<ll> adj[n];
    for(ll  i=0;i<n;i++)
    	adj[i].clear();
    for(ll i=0;i<n-1;i++)
    {
    	ll a,b;
    	cin>>a>>b;
    	adj[a-1].push_back(b-1);
    	adj[b-1].push_back(a-1);
    }
    ll ans[n];
    ll fans[n];
    ll cans[n];
    ll mini = 100000000000000000;
    for(int i=0;i<n;i++)
    {
    	if(adj[i].size() > 2)
    	{
    		cout<<"-1"<<endl;
    		return 0;
    	}
    }
    for(ll k = 0;k<6;k++)
    {
	    for(ll i=0;i<n;i++)
	    {
	    	ans[i] = 0;
	    	cans[i] = -1;
	    }
	    queue <pair< ll ,pair<ll,ll> > > q;
	    if(k==0)
	    {
	    	ans[0] = c[0][0];
	    	cans[0] = 0;
	    	ans[adj[0][0]] =  c[adj[0][0]][1];
	    	cans[adj[0][0]] = 1;
	    	q.push(make_pair(0,make_pair(0,1)));
	    	q.push(make_pair(adj[0][0],make_pair(1,0)));
	    }
	    else if(k==1)
	    {
	    	cans[0] = 0;
	    	ans[0] = c[0][0];
	    	cans[adj[0][0]] = 2;
	    	ans[adj[0][0]] =  c[adj[0][0]][2];
	    	q.push(make_pair(0,make_pair(0,2)));
	    	q.push(make_pair(adj[0][0],make_pair(2,0)));
	    }
	    else if(k==2)
	    {
	    	ans[0] = c[0][1];
	    	cans[0] = 1;
	    	cans[adj[0][0]] = 0;
	    	ans[adj[0][0]] =  c[adj[0][0]][0];
	    	q.push(make_pair(0,make_pair(1,0)));
	    	q.push(make_pair(adj[0][0],make_pair(0,1)));
	    }
	    else if(k==3)
	    {
	    	ans[0] = c[0][1];
	    	ans[adj[0][0]] =  c[adj[0][0]][2];
	    	cans[0] = 1;
	    	cans[adj[0][0]] = 2;
	    	q.push(make_pair(0,make_pair(1,2)));
	    	q.push(make_pair(adj[0][0],make_pair(2,1)));
	    }
	    else if(k==4)
	    {
	    	cans[0] = 2;
	    	cans[adj[0][0]] = 0;
	    	ans[0] = c[0][2];
	    	ans[adj[0][0]] =  c[adj[0][0]][0];
	    	q.push(make_pair(0,make_pair(2,0)));
	    	q.push(make_pair(adj[0][0],make_pair(0,2)));
	    }
	    else if(k==5)
	    {
	    	cans[0] = 2;
	    	cans[adj[0][0]] = 1;
	    	ans[0] = c[0][2];
	    	ans[adj[0][0]] =  c[adj[0][0]][1];
	    	q.push(make_pair(0,make_pair(2,1)));
	    	q.push(make_pair(adj[0][0],make_pair(1,2)));
	    }
	    while(q.size() > 0)
	    {
	    	pair< ll ,pair<ll,ll> > f = q.front();
	    	q.pop();
	    	ll node = f.first;
	    	ll pcol = f.second.second;
	    	ll ncol = f.second.first;
	    	for(ll i=0;i<adj[node].size();i++)
	    	{
	    		if(ans[adj[node][i]] == 0)
	    		{
	    			ll mcol = -1;
	    			if(pcol == 0 && ncol == 1)mcol = 2;
	    			if(pcol == 0 && ncol == 2)mcol = 1;
	    			if(pcol == 1 && ncol == 0)mcol = 2;
	    			if(pcol == 1 && ncol == 2)mcol = 0;
	    			if(pcol == 2 && ncol == 1)mcol = 0;
	    			if(pcol == 2 && ncol == 0)mcol = 1;
	    			ans[adj[node][i]] = c[adj[node][i]][mcol];
	    			cans[adj[node][i]] = mcol;
	    			q.push(make_pair(adj[node][i],make_pair(mcol,ncol)));
	    		}
	    	}
	    }
	    ll sum = 0;
	    for(ll i=0;i<n;i++)sum+=ans[i];
	    if(mini > sum )
	    {
	    	mini = sum;
	    	for(int i=0;i<n;i++)
	    		fans[i] = cans[i];
	    }
	}
	cout<<mini<<endl;
	for(int i=0;i<n;i++)
		cout<<fans[i]+1<<' ';
	cout<<endl;
	return 0;
}