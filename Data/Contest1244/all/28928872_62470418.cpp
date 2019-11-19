#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int T,n,m;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>s;
		s=' '+s;
		int a=n+1,b=0;
		for(int i=n;i>=1;--i)
			if(s[i]=='1')
				a=i;
		for(int i=1;i<=n;++i)
			if(s[i]=='1')
				b=i;
		if(a==b)
			cout<<max(n+1,max(2*a,(n-a+1)*2))<<endl;
		else if(a==n+1)
			cout<<n<<endl;
		else{
			int x=a-1,y=n-b;
			cout<<(b-a+1)*2+2*max(x,y)<<endl;
		}
	}
	return 0;
}
