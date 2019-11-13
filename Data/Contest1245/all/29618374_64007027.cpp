#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
typedef long long LL;
LL T;
string ans;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	for(int i=1;i<=200;++i)
		ans+='0';
	while(T--){
		LL n,a,b,c,x=0,y=0,z=0;
		cin>>n>>a>>b>>c;
		string s;
		cin>>s;
		for(int i=0;i<s.size();++i)
			if(s[i]=='R')
				++x;
			else if(s[i]=='P')
				++y;
			else if(s[i]=='S')
				++z;
//		cout<<x<<" "<<y<<" "<<z<<" "<<a<<" "<<b<<" "<<c<<endl;
		if((min(a,z)+min(b,x)+min(c,y))*2>=n){
			cout<<"yes\n";
			for(int i=0;i<s.size();++i)
				if(s[i]=='R'){
					if(b)
						--b,ans[i]='P';
					else
						ans[i]='0';
				}
				else if(s[i]=='P'){
					if(c)
						--c,ans[i]='S';
					else
						ans[i]='0';
				}
				else if(s[i]=='S'){
					if(a)
						--a,ans[i]='R';
					else
						ans[i]='0';
				}
			for(int i=0;i<s.size();++i)
				if(ans[i]=='0')
					if(a)
						ans[i]='R',--a;
					else if(b)
						ans[i]='P',--b;
					else ans[i]='S',--c;
			for(int i=0;i<n;++i)
				cout<<ans[i];
			cout<<endl;
		}
		else
			cout<<"no\n";
	}
	return 0;
}
