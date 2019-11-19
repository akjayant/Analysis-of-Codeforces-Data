#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

const int MN = 100005;

ll a[MN];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0; i<n; ++i)cin>>a[i];
	sort(a,a+n);
	int nm=n/2;
	ll x=0,y=0;
	for(int i=0; i<nm; ++i)x+=a[i];
	for(int i=nm; i<n; ++i)y+=a[i];
	cout<<x*x+y*y<<endl;
	return 0;
}
