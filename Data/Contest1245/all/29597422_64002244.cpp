#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
}
int n,m,t,x,y,z,res;/*
int gcd(int x,int y){
	if(!y) return x;return gcd(y,x%y);
}*/
char a[1005],b[1005];
main(){
	cin>>t;
	while(t--){
		cin>>n;
		cin>>x>>y>>z;
		scanf("%s",a+1); res=0;
		rep(i,1,n) b[i]='0';
		rep(i,1,n){
			if(a[i]=='R' && y) b[i]='P',--y,++res;
		    if(a[i]=='P' && z) b[i]='S', --z,++res;
		    if(a[i]=='S' && x) b[i]='R',--x,++res;
		}
		if(res<(n+1)/2) puts("NO");
		else{
			puts("YES");
			rep(i,1,n){
				if(b[i]=='0'){
					if(x) b[i]='R',--x;
					else if(y) b[i]='P',--y;
					else if(z) b[i]='S',--z;
				} 
			}
			rep(i,1,n) cout<<b[i];cout<<endl;
		}
	}
    
	return 0;
}
