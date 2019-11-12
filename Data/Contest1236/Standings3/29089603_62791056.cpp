#include <iostream>
using namespace std;
#define int long long
const int MOD=1000000007;

int n,m;
int ksm(int a,int b){
	int ans=1;
	while (b){
		if (b%2==0){
			b/=2;
			a*=a;
			a%=MOD;
		}
		ans*=a;
		ans%=MOD;
		b--;
	}
	return ans;
}
signed main()

{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int ans=ksm(2,m);
	ans=ksm(ans-1,n);
	cout<<ans<<endl;
	return 0;
}