#include<bits/stdc++.h>
using namespace std;
long long int mod=1e9+7;
int main(){
		int n,m; cin>>n>>m;
		int maxv= max(n,m);
		long long int A[maxv+1];
		A[0]=0;
		A[1]=1;
		A[2]=2;
		for(int i=3;i<=maxv;i++){
			A[i]=(A[i-1]%mod+A[i-2]%mod)%mod;
		}
		long long ans= ((A[n]%mod+A[m]%mod-1+mod)%mod)*2;
		cout<<ans%mod<<endl;
	return 0;
}