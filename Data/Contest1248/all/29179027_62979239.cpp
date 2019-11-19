#include <bits/stdc++.h>
using namespace std;
#define inc(i,d) for (int i=0;i<d;i++)
typedef long long ll;

int main(){
	int T;cin>>T;
	while (T--){
		ll n,m; cin>>n;
		ll c1=0,c2=0;
		inc(i,n){
			int t; scanf("%d",&t);
			if (t&1) c1++;
		}
		cin>>m;
		inc(i,m){
			int t; scanf("%d",&t);
			if (t&1) c2++;
		}
		cout<<c1*c2+(n-c1)*(m-c2)<<'\n';
	}
	return 0;
}
