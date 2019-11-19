#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;

int main() {
	// your code goes here
	long long n,m,i,memo=0,memo1=0,memo2=0,f[100005];
	cin >> n >> m;
	if(n==1&&m==1){
		cout << "2" << endl;
		return 0;
	}
	f[2]=2; f[3]=3;
	for(i=4;i<=100000;i++) f[i]=(f[i-1]+f[i-2])%mod;
	if(n==1){
		cout << 2*f[m]%mod << endl;
		return 0;
	}
	if(m==1){
		cout << 2*f[n]%mod << endl;
		return 0;
	}
	memo1 = f[n];
	memo2 = f[m];
	cout << (((memo1+memo2)%mod)*2%mod+mod-2)%mod << endl;
	return 0;
}