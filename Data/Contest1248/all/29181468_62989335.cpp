#include<bits/stdc++.h>
using namespace std;
int a1[1010000],a2[1010100]; long long a,b,n,m;
main(){
	int t;cin>>t;while(t--){
		a=b=n=m=0;
		cin>>n;for(register int i=1;i<=n;i++){
			scanf("%d",&a1[i]);
			if(a1[i]&1)a++;
		}
		cin>>m;
		for(register int k=1;k<=m;k++){
		cin>>a2[k];if(a2[k]&1)b++;
		}
		cout<<a*b+(n-a)*(m-b)<<'\n';
	} 
} 

