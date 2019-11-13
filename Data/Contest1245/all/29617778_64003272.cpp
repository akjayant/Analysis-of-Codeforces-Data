#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define fi first
#define se second
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define pii pair<ll,ll>
int main(){
	io;
	int t;
	cin>>t;
	while(t--){
		int a,b;cin>>a>>b;
		int t=__gcd(a,b);
		if(t==1)
		cout<<"Finite"<<endl;
		else
		cout<<"Infinite"<<endl;
	}
	return 0;
}



















