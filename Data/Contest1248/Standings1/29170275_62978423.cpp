#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m,t;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
	for(;t>0;t--){
		cin>>n;
		int a;
		ll o1=0,o2=0,e1=0,e2=0;
		for(int i=0 ; i<n ;i++){
			cin>>a;
			if(a%2)o1++;
			else e1++;
		}

		cin>>m;
		for(int i=0 ; i<m ;i++){
			cin>>a;
			if(a%2)o2++;
			else e2++;
		}
		cout<<o1*o2+e1*e2<<"\n";

	}
}