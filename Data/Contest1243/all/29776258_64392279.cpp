#include <iostream>
#include<bits/stdc++.h>
#define lli long long int

using namespace std;

int main() {
	// your code goes here
	lli n;
	cin>>n;
	
	for(lli i=2;i*i<=n;i++){
		if(n%i==0){
			while(n!=1 && n%i==0){
				n/=i;
			}
			
			if(n==1){
				cout<<i;
				exit(0);
			}
			else{
				cout<<1;
				exit(0);
			}
		}
	}
	
	// Prime number
	cout<<n;
	return 0;
}