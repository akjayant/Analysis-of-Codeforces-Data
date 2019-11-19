#include <bits/stdc++.h>
using namespace std;

#define ll  long long int
const ll mod = 1e9 + 7;

int main() {
	ll t,n,q;
// 	cin>>t;
	t=1;
	while(t--)
	{
	    cin>>n;
	   // cout<<n<<" ";
	    ll np=0,mp=1;
	    for(ll i=2;i<=1e6 && i<=n;i++)
	    {
	        if(n%i==0)
	        {
	            np++;
	            mp=i;
	            while(n%i==0)
	            {
	                n/=i;
	            }
	        }
	    }
	    if(n>1) 
	    {
	        np++;
	        mp=max(mp,n);
	    }
	   // cout<<np<<" ";
	    if(np>1)
	    {
	        cout<<1<<endl;
	    }
	    else
	    {
	        cout<<mp<<endl;
	    }
	   // vector<long long int> A(n,0);
	   // for(int i=0;i<n;i++)
	   // {
	   //     cin>>A[i];
	   // }
	   // sort(A.begin(),A.end());
	}
	return 0;
}
