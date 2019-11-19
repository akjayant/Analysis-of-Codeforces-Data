#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,p,w,d;
int main(){
	cin>>n>>p>>w>>d;
	for(int i=0,ed=1e5;i<=ed;i++){
		if((p-d*i)%w!=0)continue;
		LL x=(p-d*i)/w,y=i,z=n-x-y;
		if(x<0||z<0||y<0)continue;
		cout<<x<<' '<<y<<' '<<z<<endl;
		return 0;
	}puts("-1");
	return 0;
}