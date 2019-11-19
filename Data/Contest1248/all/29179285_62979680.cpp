#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 500005;

int main(){

	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif

	int t;

	cin>>t;

	while(t--){
		int n, m;
		cin>>n;
		ll ret = 0;
		ll evenx = 0, oddx = 0;
		while(n--){
			ll x;
			cin>>x;
			if(x&1) oddx++;
			else evenx++;
		}
		cin>>m;

		while(m--){
			ll x;
			cin>>x;
			if(x&1) ret += oddx;
			else ret += evenx;
		}

		cout<<ret<<endl;
	}


}