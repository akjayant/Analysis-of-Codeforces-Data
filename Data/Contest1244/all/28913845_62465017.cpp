#include<bits/stdc++.h>
using namespace std;


int main(){
	int tc , a, b, c, d, k;
	cin>>tc;
	while(tc--){
		cin>>a>>b>>c>>d>>k;
		int n = (a+c-1)/c;
		int m = (b+d-1)/d;
		if(m+n>k)cout<<"-1"<<endl;
		else cout<<n<<" "<<m<<endl;
	}
}
