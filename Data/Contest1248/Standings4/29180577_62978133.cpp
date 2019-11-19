//	Author : amnptl 
//	   Godbless
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NeedForSpeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD (1000000007); // 1e9+7
int main()
{
	NeedForSpeed();
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n; int a[n]; int odd = 0; int even = 0;
		for(int i=0; i<n; i++){
			cin>>a[i];
			if(a[i]%2)
				odd++;
			else
				even++;
		}
		int m; cin>>m; int b[m];
		for(int i=0; i<m; i++) cin>>b[i];
		ll ans = 0;

		for(int i=0; i<m; i++)
		{
			if(b[i]%2)
				ans+=odd;
			else
				ans+=even;
		}
		cout<<ans<<endl;



	}		
	return 0;
}