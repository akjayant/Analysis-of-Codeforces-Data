#include<bits/stdc++.h>
using namespace std;
long long n,i,p,q,c=0;
int main(){
	cin>>n;
	while(p*p<n) p++;
	for(i=2;i<=p;i++) if(n%i==0){
		q=n;
		while(q%i==0) q=q/i;
		if(q!=1) c=-1;
		else c=i;
		break;
	}
	if(c==-1) cout<<"1";
	else if(c==0) cout<<n;
	else cout<<c;
}