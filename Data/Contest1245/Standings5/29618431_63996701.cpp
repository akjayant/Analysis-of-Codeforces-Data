#include <bits/stdc++.h>
//#define int long long
using namespace std;

inline int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		int g=gcd(a,b);
		if(g==1) cout<<"Finite"<<endl;
		else cout<<"Infinite"<<endl;
	}
	return 0;
}