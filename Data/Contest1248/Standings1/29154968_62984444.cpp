/**
 *    author:  MySakure
 *    created: 20.10.2019 17:09:24       
**/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int maxn=1e5+10;
ll a[maxn],n;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef mysakure 
	freopen("in1.txt","r",stdin);
#endif
	cin>>n;
	ll s1=0,s2=0;
	//cerr<<"debug "<<endl;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s1+=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;++i)s2+=a[i];
	cout<<s1*s1-2*(s1-s2)*s2<<endl;

	


	return 0;
}

