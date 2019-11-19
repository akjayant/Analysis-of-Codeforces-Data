#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		if (a/c+(a%c>0)+b/d+(b%d>0)<=k){
			cout<<a/c+(a%c>0)<<" "<<b/d+(b%d>0)<<endl;
		}	
		else cout<<-1<<endl;
	}

}
