#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,a,b,c;
		string s;
		int aa=0,bb=0,cc=0;
		cin>>n>>a>>b>>c;
		cin>>s;
		int l = s.size();
		for(int i=0;i<l;i++) if(s[i]=='R') aa++;else if(s[i]=='P') bb++;else cc++;
		string ss = "";
		for(int i=0;i<l;i++) ss+=',';
		int ans = min(aa,b)+min(bb,c)+min(cc,a);
		if(n%2==0 )
		{
			if(ans>=n/2) 
			{
				for(int i=0;i<l;i++) if(s[i]=='R' && b>0) {ss[i]='P',b--;}
				else if(s[i]=='P' && c>0) {ss[i]='S',c--;}
				else if(s[i]=='S' && a>0) {ss[i]='R',a--;}
				for(int i=0;i<l;i++) if(ss[i]==',') 
				{if(a>0) {ss[i]='R',a--;}
				else if(b>0) {ss[i]='P',b--;}
				else if(c>0) {ss[i]='S',c--;}  
				}	
				cout<<"YES\n"<<ss<<endl;
			}
			else cout<<"NO\n";
		} 
		else if(n%2==1)
		{
			if(ans>=n/2+1) 
			{
				for(int i=0;i<l;i++) if(s[i]=='R' && b>0) {ss[i]='P',b--;}
				else if(s[i]=='P' && c>0) {ss[i]='S',c--;}
				else if(s[i]=='S' && a>0) {ss[i]='R',a--;}
				for(int i=0;i<l;i++) if(ss[i]==',') 
				{if(a>0) {ss[i]='R',a--;}
				else if(b>0) {ss[i]='P',b--;}
				else if(c>0) {ss[i]='S',c--;}  
				}	
				cout<<"YES\n"<<ss<<endl;
			}
			else cout<<"NO\n";
		}
	}
	return 0;
}


/*
2
6
2 2 2 
RPSSPR
6
3 2 1
RPSRPS

*/