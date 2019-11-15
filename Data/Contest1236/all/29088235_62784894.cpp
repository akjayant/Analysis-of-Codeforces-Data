#include<iostream>
using namespace std;
int t,a,b,c;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int anss=0,ans=0;
		ans = min(b,c/2);
		b-=ans;
		ans*=3;
		if(b){
			anss=min(a,b/2);
		}
		cout<<ans+anss*3<<endl;
	}
} 