#include <iostream>
#define rnt register int
using namespace std;
string A,B;
bool vis[100];
int T,n,a,b,c,num;
int main(){
	cin>>T;
	Work:if(T){
		cin>>n>>a>>b>>c>>A;
		B=A;num=0;
		for(rnt i=1;i<=n;i=-~i) vis[i-1]=false;
		for(rnt i=1;i<=n;i=-~i){
			if(A[i-1]=='R' && b) --b,B[i-1]='P',vis[i-1]=true,num=-~num;
			if(A[i-1]=='P' && c) --c,B[i-1]='S',vis[i-1]=true,num=-~num;
			if(A[i-1]=='S' && a) --a,B[i-1]='R',vis[i-1]=true,num=-~num;
		}
		for(rnt i=1;i<=n;i=-~i) if(!vis[i-1]) if(a) --a,B[i-1]='R';
		else if(b) --b,B[i-1]='P';
		else --c,B[i-1]='S';
		if(num>=(n+1)/2) cout<<"YES"<<endl<<B<<endl;
		else cout<<"NO"<<endl;
		--T;goto Work;
	}
	return 0;
}
