#include<iostream>
using namespace std;
long long n,t,p[100005],q[100005],m;
int main(){
	cin>>t;
	while(t--){
		cin>>m;
		long long ans=0,ans2,an2,an=0;
		for(int i=1;i<=m;++i){
			cin>>p[i];
			if(p[i]%2)ans++;
		}ans2=m-ans;
		cin>>m;
		for(int i=1;i<=m;++i){
			cin>>q[i];
			if(q[i]%2)an++;
		}an2=m-an;
		cout<<ans*(an)+ans2*an2<<endl;
		
	}
} 