#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int x=a/c+(a%c!=0),y=b/d+(b%d!=0);
		if(x+y>k)cout<<"-1\n";
		else cout<<x<<' '<<y<<'\n';
	}
	return 0;
}