#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e5+7;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a,a+n);
	ll ans=0;
	if(n&1){
		for(int i=0;i<n/2;i++)
			ans+=a[i];
		cout<<ans*ans+(sum-ans)*(sum-ans)<<endl;
	}else{
		for(int i=0;i<n/2;i++)
			ans+=a[i];
		cout<<ans*ans+(sum-ans)*(sum-ans)<<endl;
	}
	return 0;
} 