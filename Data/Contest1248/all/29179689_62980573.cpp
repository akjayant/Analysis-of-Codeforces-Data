#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define LL long long int

int main() {
	LL n,tmp;
	cin>>n;
	vector<LL> stx;
	for(int i=0;i<n;++i) {
		cin>>tmp;
		stx.push_back(tmp);
	}
	sort(stx.begin(),stx.end());
	LL x=0,y=0;
	for(int i=0;i<n/2;++i) x+=stx[i];
	for(int i=n/2;i<n;++i) y+=stx[i];
	cout<<x*x+y*y<<"\n";
}