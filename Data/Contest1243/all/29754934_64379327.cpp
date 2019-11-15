#include<bits/stdc++.h>
using namespace std;
long long k,i,j,n,a[1001],x,b[1001],sumi;
int main(){
	cin>>k;
	for(j=1;j<=k;j++){
		cin>>n;
		for(i=1;i<=n;i++) a[i]=0;
		for(i=1;i<=n;i++){
			cin>>x;
			a[x]++;
		}
		sumi=0;
		for(i=1;i<=n;i++){
			b[i]=n-sumi;
			sumi=sumi+a[i];
		}
		for(i=n;i>0;i--) if(b[i]>=i){
			sumi=i;
			break;
		}
		cout<<sumi<<endl;
	}
}