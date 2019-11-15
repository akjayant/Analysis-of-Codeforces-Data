#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define MAXN 10005
int gcd(int a,int b){
	while(b^=a^=b^=a%=b);
	return a;
}
int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(gcd(a,b)==1)	cout<<"Finite"<<endl;	
		else	cout<<"Infinite"<<endl;
	}
	return 0;
}
