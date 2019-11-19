#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=1e5+10;
const LL p=1e9+7;

LL g[N];

int main() {
	int n,m;
	cin>>n>>m;
	g[1]=1,g[2]=2;
	int len=max(n,m);
	for(int i=3;i<=len;i++) g[i]=g[i-1]+g[i-2]%p;
	LL Ans=g[n]+g[m]%p;
//	cout<<g[n]<<' '<<g[m]<<endl;
	Ans--;
	if(Ans<0) Ans+=p;
	Ans*=2;
	Ans%=p;
	cout<<Ans<<endl;
}
		
		
