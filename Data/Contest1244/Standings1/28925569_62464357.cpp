#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int _=(scanf("%d",&_),_);_;_--){
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int t1=a/c+(a%c!=0);
		int t2=b/d+(b%d!=0);
		if(t1+t2>k)puts("-1");
		else {
			printf("%d %d\n",t1,t2);
		}
	}
	return 0;
}