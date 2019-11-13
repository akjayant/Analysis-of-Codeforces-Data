#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		string a,b;
		for(int i=0;i<n;i++){
			if(s[i]!=t[i]){
				a+=s[i];
				b+=t[i];
			}
		}
		if(a.size()>=3)	cout<<"No\n";
		else if(a.size()==0)	cout<<"Yes\n";
		else if(a.size()==1)	cout<<"No\n";
		else if(a.size()==2){
			if(a[0]==a[1]&&b[1]==b[0])	cout<<"Yes\n";
			else cout<<"No\n";
		}
	}	
	return 0;
}