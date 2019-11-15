#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	ios::sync_with_stdio(false);
	int _;cin>>_;
	while(_--){
		int a,b;cin>>a>>b;
		if(gcd(a,b)>1){
			cout<<"Infinite"<<endl;
		} else {
			cout<<"Finite"<<endl;
		}
	}	
	return 0;
}