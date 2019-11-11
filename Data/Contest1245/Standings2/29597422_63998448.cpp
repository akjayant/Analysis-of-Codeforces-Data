#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
}
int n,m,t;
int gcd(int x,int y){
	if(!y) return x;return gcd(y,x%y);
}
main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
        if(gcd(n,m)==1) cout<<"Finite"<<endl;
        else cout<<"Infinite"<<endl;
	}
    
	return 0;
}
