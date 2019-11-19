#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int T;
int x,y,p,q;
ll ca,cb,ta,tb;
inline int read(){
	int x=0;scanf("%d",&x);return x;
} 
int main(){
	T=read();
	while(T--){
		x=y=p=q=0;
		ca=cb=ta=tb=0;
		x=read();
		for(int i=1;i<=x;i++){
			p=read();
			if(p%2==1) ca++;
			else cb++;
		}
		y=read();
		for(int i=1;i<=y;i++){
			q=read();
			if(q%2==1) ta++;
			else tb++;
		}
		printf("%lld\n",ca*ta+cb*tb);
	}
	return 0;
} 