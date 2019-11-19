#include<bits/stdc++.h>
using namespace std;
long long n,p,w,d,t,x,y,tmp;

int main(){
	cin>>n>>p>>w>>d;
	t=__gcd(w,d);
	x=p/w;
	tmp=x-d-1;
	while(x>=0&&x>=tmp){
		if((p-w*x)%d==0){
			y=(p-w*x)/d;
			if(x+y>n) puts("-1");	
			else cout<<x<<" "<<y<<" "<<n-x-y<<endl;
			return 0;
		}
		x--;
	}
	puts("-1");

	return 0;
}