#include<iostream>

using namespace std;

int n;
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int main(){
	int t;
cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(gcd(a,b)==1){
			cout<<"Finite"<<endl;
		}
		else cout<<"Infinite"<<endl;
	}
	return 0;
}