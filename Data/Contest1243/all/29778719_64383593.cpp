#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
	fast;
	ull n;
	cin>>n;
	vector<ull> v;
	ull g=n;
	for(ull i=2;i<=sqrt(n);i++){
		if(n%i==0){
			g=__gcd(g,i);
			g=__gcd(g,n/i);
		}
	}
	cout<<g;
	return 0;
}
