#include <bits/stdc++.h>
using namespace std;
int t;
int a,b,c,n;
int main(){
	cin>>t;
	for(int i=0; i<t;i++){
		cin>>a>>b>>c;
		n=min(b,c/2);
		n+=min(a,(b-n)/2);
		cout<<3*n<<endl;
	}
}