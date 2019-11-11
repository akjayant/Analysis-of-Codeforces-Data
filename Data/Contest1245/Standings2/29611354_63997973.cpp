//Coded by dst
#include<iostream>
#include<cstdio>
using namespace std;
int T;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	int i,x,y;
	cin>>T;
	for(i=1;i<=T;i++){
		cin>>x>>y;
		if(gcd(x,y)==1)
			cout<<"Finite"<<endl;
		else
			cout<<"Infinite"<<endl;
	}
	return 0;
}