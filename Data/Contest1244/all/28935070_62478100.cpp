#include<iostream>
#include<cmath>
using namespace std;
typedef long long int llint;
int bio[100005];
int main()
{
	llint n,p,w,d;
	cin >> n >> p >> w >> d;
	llint x=p%w,win=p/w;
	bio[x%d]=1;
	if(x%d==0 && win+x/d<=n) {
		cout << win << " " << x/d << " " << n-win-x/d;
		return 0;
	}
	if(p==0) {
		cout << "0 0 " << n;
		return 0;
	}
	for(int i=0;win>0;i++) {
		x+=w;
		win-=1;
		if(x%d==0 && win+x/d<=n) {
			cout << win << " " << x/d << " " << n-win-x/d;
			return 0;
		}
		if(bio[x%d]) {
			cout << -1;
			return 0;
		}
		bio[x%d]=1;
	}
	cout << -1;
	return 0;
}
