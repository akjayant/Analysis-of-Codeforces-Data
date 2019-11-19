#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,d,k,t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>k;
		int a1=ceil(a/(c*1.0));
		int b1=ceil(b/(d*1.0));
		if(a1+b1<=k){
			cout<<a1<<" "<<b1<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
}
