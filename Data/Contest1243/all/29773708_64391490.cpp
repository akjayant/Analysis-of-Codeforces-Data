#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long long N;
	cin>>N;
	long long i,sq=sqrt(N);
	long long a=0,b=0;
	for(i=2;i<=sq;i++) {
		if(N%i==0) {
			if(a==0) {
				a=i;
				long long tmp=N/i;
				if(tmp%a!=0) {
					b=tmp;
					break;
				}
			} else {
				if(i%a!=0) {
					b=i;
					break;
				}
				long long tmp=N/i;
				if(tmp%a!=0) {
					b=tmp;
					break;
				}
			}
		}
	}
	if(a&&b) {
		cout<<1<<endl;
		return 0;
	}
	if(!a&&!b) {
		cout<<N<<endl;
	} else {
		cout<<a<<endl;
	}
	return 0;
}