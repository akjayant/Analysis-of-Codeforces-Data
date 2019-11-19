#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll a[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll a1=0,a2=0;
	for(int i=1;i<=n/2;++i)
		a1+=a[i];
	for(int i=n/2+1;i<=n;++i)
		a2+=a[i];
	cout<<a1*a1+a2*a2<<'\n';
	return 0;
}
