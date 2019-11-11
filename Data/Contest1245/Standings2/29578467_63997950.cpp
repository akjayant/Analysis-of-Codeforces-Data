#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int x,y;
		cin>>x>>y;
		if(gcd(x,y)==1) cout<<"Finite"<<'\n';
		else cout<<"Infinite"<<'\n';
	}
	return 0;
}

