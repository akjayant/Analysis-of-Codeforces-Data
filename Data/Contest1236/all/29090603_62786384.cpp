#include<iostream>
using namespace std;

int main() {
	int t,a,b,c,p,q;
	cin>>t;
	for(int i=0;i<t;++i) {
		cin>>a>>b>>c;
		q = (b<c/2?b:c/2);
		b-=q;
		p = (a<b/2?a:b/2);
		cout<<3*(p+q)<<"\n";
	}
}