#include<iostream>
using namespace std;
#define LL long long int

int main() {
	LL t,tmp,n;
	LL p[2],q[2];
	cin>>t;
	for(int iii=0;iii<t;++iii) {
		for(int i=0;i<2;++i) p[i]=0;
		for(int i=0;i<2;++i) q[i]=0;
		cin>>n;
		for(int i=0;i<n;++i) {
			cin>>tmp;
			++p[tmp%2];
		}
		cin>>n;
		for(int i=0;i<n;++i) {
			cin>>tmp;
			++q[tmp%2];
		}
		cout<<p[0]*q[0]+p[1]*q[1]<<"\n";
	}
}