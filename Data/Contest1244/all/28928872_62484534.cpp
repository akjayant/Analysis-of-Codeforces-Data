#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
LL n,p,w,d;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>p>>w>>d;
	for(LL y=0;y<=1e5;++y){
		if((p-y*d)%w==0){
			LL x=(p-y*d)/w,z=n-x-y;
			if(x<0||z<0)
				continue;
			cout<<x<<" "<<y<<" "<<n-x-y<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
