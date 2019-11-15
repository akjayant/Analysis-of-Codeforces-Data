#include <bits/stdc++.h>
using namespace std;

#define ll  long long int
const ll mod = 1e9 + 7;

int main() {
	ll t,n,q;
	cin>>t;
// 	t=1;
	while(t--)
	{
	    cin>>n;
	    vector<long long int> A(n,0);
	    for(int i=0;i<n;i++)
	    {
	        cin>>A[i];
	    }
	    sort(A.begin(),A.end());
	    ll ans=0,mini=1001;
	    for(ll i=0;i<n;i++)
	    {
	        if(A[i]>=n-i)
	        {
	            ans=max(ans,n-i);
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
