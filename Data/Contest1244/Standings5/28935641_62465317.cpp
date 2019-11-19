#include <bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d>>k;
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y>k) puts("-1");
		else cout<<x<<' '<<k-x<<endl;
	}
}