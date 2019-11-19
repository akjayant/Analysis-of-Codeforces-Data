#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,p,d,w;
signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>p>>d>>w;
	int x=-1,y=-1,z=-1;
	for(int i=0;i<=min(10000000ll,n);++i){
		int j=(p-i*d)/w;
		if(j>=0&&(p-i*d)%w==0&&j<=n-i){
			x=i;
			y=j;
			z=n-i-j;
		}
		j=(p-i*w)/d;
		if(j>=0&&(p-i*w)%d==0&&j<=n-i){
			x=j;
			y=i;
			z=n-i-j;
		}
	}
	if(x!=-1){
		cout<<x<<' '<<y<<' '<<z;
		return 0;
	}
	if(p%w==0){
		x=p/w;
		if(x<=n){
			cout<<x<<' '<<0<<n-x;
			return 0;
		}
	}
	if(p%d==0){
		x=p/d;
		if(x<=n){
			cout<<0<<' '<<x<<n-x;
			return 0;
		}
	}
	cout<<-1;
}