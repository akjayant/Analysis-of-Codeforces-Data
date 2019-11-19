#include <bits/stdc++.h>

using namespace std;
long long t,n,m,p,q,pe,qe,po,qo;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>t;
	while(t--){
		po=0;qo=0;qe=0;pe=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>p;
			if(p%2==0) pe++;
			else po++;
		}
		cin>>m;
		for(long long i=1;i<=m;i++){
			cin>>q;
			if(q%2==0) qe++;
			else qo++;
		}
		cout<<po*qo+pe*qe<<endl;
	}
}


