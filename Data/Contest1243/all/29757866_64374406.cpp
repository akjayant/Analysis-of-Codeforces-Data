#include<bits/stdc++.h>
using namespace std;
const int N=5100;
typedef long long ll;
const ll MOD=1e9+7LL;
int a[N];
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--)
    {
    	int n;
    	cin>>n;
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>a[i];
    	}
    	sort(a,a+n);
    	int ans=0;
    	for (int i = 0; i <= n; ++i)
    	{
    		int x=0;
    		for (int j = 0; j < n; ++j)
    		{
    			if(a[j]>=i)
    				x++;
    		}
    		if(x>=i)
    			ans=i;
    	}
    	cout<<ans<<"\n";
    }
    return 0;   
}