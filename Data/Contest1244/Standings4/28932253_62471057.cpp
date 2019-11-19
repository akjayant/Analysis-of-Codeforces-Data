#include<bits/stdc++.h>
using namespace std;
int t,a[2019],b,c,j,n,k,i,u;
char x;
int main(){
	cin>>t;
	for(i=1;i<=t;i++){
		b=-1;
		c=-1;
		cin>>n;
		for(j=1;j<=n;j++){
			cin>>x;
			a[j]=x-48;
		}
		for(j=1;j<=n;j++) if(a[j]==1){
			b=j;
			break;
		}
		for(j=n;j>0;j--) if(a[j]==1){
			c=j;
			break;
		}
		if(b==-1) cout<<n<<endl;
		else if(2*c>=2*(n-b+1)) cout<<2*c<<endl;
		else cout<<2*(n-b+1)<<endl;
	}
}