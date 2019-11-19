#include<iostream>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll f[100010];
int main(){
	int n,m;
	cin>>n>>m;
	f[0]=f[1]=1;f[2]=2;
	for(int i=3;i<=max(m,n);i++){
		f[i]=f[i-1]+f[i-2];
		f[i]%=MOD;
	}
	ll ans=f[m];
	for(int i=0;i<n-1;i++){
		ans+=f[i];
		ans%=MOD;
	}
	cout<<ans*2%MOD;
	return 0;
}