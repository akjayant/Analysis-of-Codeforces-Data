#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		string s;
		cin>>n>>s;
		int l=-1,r=-1;
		for(int i=0;i<n;i++)
			if(s[i]=='1')l=i;
		for(int i=n-1;i>=0;i--)
			if(s[i]=='1')r=n-i-1;
		cout<<max(n,max(l,r)*2+2)<<'\n';
	}
	return 0;
}