/**
 *    author:  MySakure
 *    created: 20.10.2019 17:05:21       
**/
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
long long t,n,m;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef mysakure 
	freopen("in1.txt","r",stdin);
#endif
	cin>>t;
	while(t--){
		cin>>n;
		long long a=0,b=0,c=0,d=0;
		while(n--){
			int tmp;
			cin>>tmp;
			if(tmp&1)a++;
			else b++;
		}
		cin>>m;
		while(m--){
			int tmp;
			cin>>tmp;
			if(tmp&1)c++;
			else d++;
		}
		cout<<a*c+b*d<<'\n';


	}
	


	return 0;
}

