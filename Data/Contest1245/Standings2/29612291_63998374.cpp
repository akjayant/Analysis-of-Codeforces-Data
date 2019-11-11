#include<iostream>
#include<algorithm>
using namespace std;
const long long mx=1e9;
const long long mod=1e9+7;
const long long maxn=2e5+10;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		if(gcd(x,y)==1){
			cout<<"Finite"<<endl;
		}else{
			cout<<"Infinite"<<endl;
		}
	}
	return 0;
}