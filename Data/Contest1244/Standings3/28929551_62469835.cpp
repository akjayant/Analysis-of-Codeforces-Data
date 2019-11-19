#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,k;
int u,v;

int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d>>k;
		u=(a-1)/c+1;
		v=(b-1)/d+1;
		if(u+v>k) puts("-1");
		else printf("%d %d\n",k-v,v); 
	}

	return 0;
}