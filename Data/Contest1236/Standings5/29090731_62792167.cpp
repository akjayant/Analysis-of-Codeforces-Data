#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const long long mod = 1000000007;

long long pot(long long a, long long n){
	long long ans = 1;
	vector<int> Bin;
	while(n > 0){
		Bin.push_back(n % 2);
		n /= 2;
	}
	for(int i=0; i<Bin.size(); i++,a=(a*a)%mod){
		if(Bin[i] == 1)
		ans = (ans * a) % mod;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	long long n,m,ans,i;
	cin>>n>>m;
	ans = pot(2,m);
	ans = (mod + ans - 1) % mod;
	ans = pot(ans, n);
	cout<<ans<<endl;
}