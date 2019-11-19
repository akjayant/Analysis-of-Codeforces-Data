#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll p[N],q[N],a=0,n,b=0;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i = 0;i < n;++i)cin>>p[i];
	sort(p,p+n);
	for(int i = 0;i < n;++i){
		if(i<=n/2-1)a+=p[i];
		else b+=p[i];
	}
	cout<<a*a+b*b<<endl;
	return 0;
}