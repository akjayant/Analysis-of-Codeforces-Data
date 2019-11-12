#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=32e4;

int main(){
	int a,b,c,t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int d=min(c/2,b);
		int e=min((b-d)/2,a);
		cout<<(d+e)*3<<'\n';
	}
	return 0;
}