#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() 
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
      cin>>a[i];
    sort(a,a+n);
    ll h=0,l=0;
    ll s=0,e=n-1;
    while(s<e)
    {
    	h+=a[s];
    	l+=a[e];
    	s++;
    	e--;
	}
	if(s==e)
	  l+=a[e];
	ll ans=(l*l)+(h*h);
	cout<<ans<<endl;
    return 0;
}
