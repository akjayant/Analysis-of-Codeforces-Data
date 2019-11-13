/*Arnab's Code
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb(n) push_back(n)
#define take(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define takes(a,n,st) for(ll i=st;i<n+st;i++)cin>>a[i]
ll sum(ll a[],ll n,ll s){ for(ll i=0;i<n;i++)s+=a[i]; return s;}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ll t,a,b,c,d,e,tot;
	cin>>t;
	while(t--){
		tot=0;
		cin>>a>>b>>c;
		d=min(b,c/2);
		tot+=d;
		b-=d;
		e=min(a,b/2);
		tot+=e;
		cout<<tot*3<<endl;
	}
	return 0;
}