#include<bits/stdc++.h>
using namespace std;
long long n,p,w,d,i,x=-1,y=-1,z=-1,u;
int main(){
	cin>>n>>p>>d>>w;
	for(i=0;i<d;i++){
		if(p<i*w) break;
		else if((p-i*w)%d==0){
			x=i;
			y=(p-i*w)/d;
			break;
		}
	}
	if(x>=0){
		if(x+y>n) cout<<"-1";
		else cout<<y<<" "<<x<<" "<<n-x-y;
	}
	else cout<<"-1";
}