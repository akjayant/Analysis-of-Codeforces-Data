#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n,m,vl[10100100][2];
main(){
	cin>>n>>m;
	vl[1][0]=2;
	for(int i=1;i<=110000;i++){
		(vl[i+1][0]+=(vl[i][0]+vl[i][1]))%=mod;
		(vl[i+1][1]+=vl[i][0])%=mod;
	}
	cout<<(vl[n][0]+vl[n][1]+vl[m][0]+vl[m][1]-2)%mod;
}
