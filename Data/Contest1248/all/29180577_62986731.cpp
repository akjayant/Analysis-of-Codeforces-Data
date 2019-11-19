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
	int n; cin>>n; ll a[n];
	for(int i=0; i<n; i++) cin>>a[i];
	sort(a,a+n); ll p=0,q=0;
	for(int i=0; i<(n/2); i++)
		p += a[i];
	for(int i=(n/2); i<n; i++)
		q += a[i];
	ll ans = (p*p)+(q*q);
	cout<<ans<<endl;
	return 0;
}