#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[1000050];
int main(){
	ll n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);	
		}
		sort(a,a+n);
		ll x=0,y=0;
		for(int i=0;i<n/2;i++){
			x+=a[i];
		}
		for(int i=n/2;i<n;i++){
			y+=a[i];
		}
		cout<<x*x+y*y<<endl;
	}
	return 0;
}

