#include<iostream>
using namespace std;
long long n,m,p,c=1000000007;
long long pow(long long a,long long b){
	long long ans =1;
	while(b){
		if(b&1)ans=(ans*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return ans;
}
int main(){
	cin>>n>>m;
	cout<<pow(pow(2,m)-1,n);
} 