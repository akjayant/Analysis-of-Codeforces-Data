#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100005];

int main(){

	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif

	int n;
	cin>>n;

	for(int i = 1; i<=n; i++){
		cin>>a[i];
	}

	ll x = 0, y = 0;

	sort(a+1, a+n+1);

	for(int i = 1; i<=n/2; i++){
		 y+= a[i];
		 a[i] = -1;
	}
	for(int i = n; i>=1; i--){
		if(a[i]==-1) break;
		x += a[i];
	}

	cout<<x*x + y*y<<endl;







}