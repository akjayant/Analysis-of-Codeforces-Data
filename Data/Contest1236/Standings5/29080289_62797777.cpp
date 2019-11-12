#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a[n];
    int p = 0;
    int inc = 1;
    for(int i=1;i<=n*n;i++)
    {
    	a[p].push_back(i);
    	if(inc == 1)
    	{
    		p++;
    		if(p==n)
    		{
    			p = n-1;
    			inc = 0;
    		}
    	}
    	else
    	{
    		p--;
    		if(p==-1)
    		{
    			p = 0;
    			inc = 1;
    		}
    	}
    }
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    		cout<<a[i][j]<<' ';
    	cout<<endl;
    }
	return 0;
}