#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll p[N],q[N];
int main()
{
	ios::sync_with_stdio(0);
	ll T ,ans,a1,a2,b1,b2;
	cin>>T;int n,m;
	while(T--){
		a1=a2=b1=b2=ans = 0;
		cin>>n;
		for(int i = 0;i < n;++i){
			cin>>p[i];
			if(p[i]%2)a1++;
			else b1++;
		}
		cin>>m;
			for(int i = 0;i < m;++i){
			cin>>q[i];
			if(q[i]%2)a2++;
			else b2++;
		}
		cout<<a1*a2+b1*b2<<endl;
	}
	return 0;
}