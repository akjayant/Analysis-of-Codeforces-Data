#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v vector<ll> 
#define vv vector<v>
#define p pair<ll,ll>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		v arr(n+1);
		for (int i=1; i<=n; i++)
			cin>>arr[i];
		sort(arr.begin()+1,arr.end());
		ll ans=0;
		for (int i=n; i>=1; i--)
		{
			if (arr[i]<n-i+1)
				break;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}