#include<bits/stdc++.h>
using namespace std;
#define ll long long 

set<int>s;

int main(){
	int t;cin>>t;
	while(t--){
		int a,b;cin>>a>>b; 
		if(__gcd(a,b)==1)puts("Finite");
		else puts("Infinite");
	}	
}

/*
0* 1 2 3* 4 5 6* 7* 8 9* 10* 11 12* 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28

*/