#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n,p,w,d;
long long multiply(long long a,long long b,long long mod){
	long long ret=0;
	while(b){
		if(b&1){
			ret=(ret+a)%mod;
		}
		a=(a+a)%mod;
		b>>=1;
	}
	return ret;
}
int exgcd(long long &x,long long &y,long long a,long long b){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int g=exgcd(x,y,b,a%b);
	int z=x;
	x=y;
	y=z-(a/b)*y;
	return g;
}
int main(){
	cin>>n>>p>>w>>d;
	long long x,y;
	long long g=exgcd(x,y,w,d);
	if(p%g!=0){
		printf("-1\n");
		return 0;
	}
	x%=d;
	x=(x+d)%d;
	x=multiply(x,p/g,d);
	y=(p-(x*w))/d;
	d/=g;
	w/=g;
	long long m=d-w; //差值
	if(x<0&&y<0){
		printf("-1\n");
		return 0;
	}
	if(x<0){
		x+=d;
		y-=w;
	}
	if(y<0){
		x-=d;
		y+=w;
	}
	if(x<0||y<0){
		printf("-1\n");
		return 0;
	}
	if(m<0){
		long long k=y/w;
		x+=k*d;
		y-=k*w;
		if(x+y<=n){
			cout<<x<<" "<<y<<" "<<n-x-y<<endl;
		}
		else{
			printf("-1\n");
		}
		return 0;
	}
	else if(m==0){
		if(x+y<=n){
			cout<<x<<" "<<y<<" "<<n-x-y<<endl;
		}
		else{
			printf("-1\n");
		}
		return 0;
	}
	long long k=x/d;
	x-=k*d;
	y+=k*w;
	if(x+y<=n){
		cout<<x<<" "<<y<<" "<<n-x-y<<endl;
	}
	else{
		printf("-1\n");
	}
	return 0;
}