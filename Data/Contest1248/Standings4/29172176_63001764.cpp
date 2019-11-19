#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int N = 1e5+7;
typedef long long ll;
const ll mod = 1e9+7;
using namespace std;
int n,m;
ll f[N],ff[N],ans[N],xx[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m; cin>>n>>m;
	f[1]=2; f[2]=4;
	for(int i=3;i<=max(n,m);i++){
		f[i]=(f[i-1]+f[i-2])%mod;
	}
	ff[1]=0; ff[2]=2;
	for(int i=3;i<=max(n,m);i++){
		ff[i]=(ff[i-1]+ff[i-2])%mod;
	}
	ans[1]=0; ans[2]=2;
	for(int i=3;i<=max(n,m);i++){
		ans[i]=(ans[i-1]+ff[i])%mod;
	}
	cout<<(f[n]+ans[m])%mod<<endl;
	return 0;
} 