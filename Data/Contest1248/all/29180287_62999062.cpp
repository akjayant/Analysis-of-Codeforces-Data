#include <bits/stdc++.h>
#define Tree int h,int l,int r
#define Left 2*h,l,(l+r)/2
#define Right 2*h+1,(l+r)/2,r
#define F first
#define S second
#define Pb push_back
using namespace std;
long long n,m,mod=1e9+7,a[100005],b[100005],x,ANS;
main () {
	ios::sync_with_stdio(false);

	cin>>n>>m;
	
	a[1]=2,a[2]=4;
	
	for (int i=3; i<=1e5; i++) {
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	
	ANS=a[m];
	
	if (2<=n) ANS=ANS+2;

	for (int i=3; i<=n; i++) 
		ANS=(ANS+a[i-2])%mod;
	
	cout<<ANS<<endl;
}