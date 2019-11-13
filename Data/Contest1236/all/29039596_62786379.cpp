#include<bits/stdc++.h>
using namespace std;




int main(){
	
	int tt;
	cin>>tt;
	while(tt--){
		int a,b,c;
		cin>>a>>b>>c;
		int sum=0;
		int temp=c/2;
		int mn=min(temp,b);
		sum=3*mn;
		b-=mn;
		temp=b/2;
		mn=min(temp,a);
		sum+=3*mn;
		cout<<sum<<"\n";
	}
}