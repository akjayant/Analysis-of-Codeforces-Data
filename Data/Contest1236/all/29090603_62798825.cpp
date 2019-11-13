#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;++i) {
		for(int j=0;2*j<n-1;++j)
			cout<<2*n*j+1+i<<" "<<2*n*j+2*n-i<<" ";
		if(n%2)
			cout<<2*n*(n/2)+i+1<<"\n";
		else
			cout<<"\n";
	}
}	