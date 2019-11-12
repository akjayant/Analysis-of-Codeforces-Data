#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,T;
signed main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		if(b>=c/2){
			int res=(min((b-c/2)/2,a)+c/2)*3;
			cout<<res<<endl;
		}
		else{
			cout<<min(b,c/2)*3<<endl;
		}
	}
	return 0;
}

