#include <bits/stdc++.h>
using namespace std;
#define inc(i,d) for (int i=0;i<d;i++)
typedef long long ll;

const ll P=1e9+7;
ll a[1000010][4],b[1000010];

int main(){
	b[1]=1; b[0]=1;
	for (int i=2;i<=1000005;i++){
		b[i]=(b[i-1]+b[i-2])%P;
		//cout<<b[i]<<' ';
	}
	int n,m; cin>>n>>m;
	cout<<((b[n]+b[m]-1+P))*2%P<<'\n';
	return 0;
}
