#include<iostream>

using namespace::std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int r,p,si;
		cin>>r>>p>>si;
		string s;
		char t[101]={};
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='R' && p) t[i]='P',p--;
			else if(s[i]=='P' && si) t[i]='S',si--;
			else if(s[i]=='S' && r) t[i]='R',r--;
		}
		for(int i=0;i<n;i++)
			if(!t[i]){
				if(r) t[i]='R',r--;
				else if(p) t[i]='P',p--;
				else t[i]='S',si--;
			}
		int ans=0;
		for(int i=0;i<n;i++)
			if((s[i]=='R' && t[i]=='P')||(s[i]=='P' && t[i]=='S')||(s[i]=='S' && t[i]=='R')) ans++;
		cout<<(ans>=(n+1)/2?"YES\n"+string(t):"NO")<<'\n';
	}
}
