#include<bits/stdc++.h> 
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,n,cnt=0,a2=0,b2=0,c2=0;
		string s,ans;
		cin>>n>>a>>b>>c>>s;
		for(int i=0;i<s.length();i++){
			if(s[i]=='R')a2++;
			if(s[i]=='P')b2++;
			if(s[i]=='S')c2++;
		}
		cnt=min(a,c2)+min(b,a2)+min(c,b2);
		//cout<<"cnt="<<cnt<<endl;
		if(cnt*2<n){
			cout<<"NO"<<endl;
			continue;
		}
		int x=a-c2,y=b-a2,z=c-b2;
		for(int i=0;i<s.length();i++){
			if(s[i]=='R'){
				if(b>0)ans+='P',--b;
				else{
					if(x>0)ans+='R',--x;
					else if(y>0)ans+='P',--y;
					else if(z>0)ans+='S',--z;
				}
			}
			if(s[i]=='P'){
				if(c>0)ans+='S',--c;
				else{
					if(x>0)ans+='R',--x;
					else if(y>0)ans+='P',--y;
					else if(z>0)ans+='S',--z;
				}
			}
			if(s[i]=='S'){
				if(a>0)ans+='R',--a;
				else{
					if(x>0)ans+='R',--x;
					else if(y>0)ans+='P',--y;
					else if(z>0)ans+='S',--z;
				}
			}
		}
		cout<<"YES"<<endl<<ans<<endl;
	}
	return 0;
}
