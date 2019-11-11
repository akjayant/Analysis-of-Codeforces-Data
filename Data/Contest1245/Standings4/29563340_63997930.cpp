#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef long double ld;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t; 
	cin>>t; 
	while(t--){
		int a,b; 
		cin>>a>>b; 
		int g = __gcd(a,b);
		if(g==1){
			cout<<"Finite\n";
		}
		else cout<<"Infinite\n";
	}
	return 0;
}
