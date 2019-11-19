#include<bits/stdc++.h>
using namespace std;
int t,n,a;

int main(){
	cin>>t;
	while(t--){
		int flag=false;
		cin>>n;
		int ans=n;
		for(int i=1;i<=n;i++){
			scanf("%1d",&a);
			if(a==1) ans=max(ans,max(2*i,2*(n-i+1))); 
		}
		cout<<ans<<endl;
	}

	return 0;
}