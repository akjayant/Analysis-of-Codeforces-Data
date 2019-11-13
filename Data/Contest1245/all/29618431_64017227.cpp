#include <bits/stdc++.h>
using namespace std;

char ans[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++) ans[i]='*';
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='R') cnt1++;
			if(s[i]=='P') cnt2++;
			if(s[i]=='S') cnt3++;
		}
		int anss=min(cnt1,b)+min(cnt2,c)+min(cnt3,a);
		int num=(n+1)/2;
		if(anss>=num){
			cout<<"YES"<<endl;
			int num1=min(cnt1,b);
			int num2=min(cnt2,c);
			int num3=min(cnt3,a);
			int val1=0,val2=0,val3=0;
			for(int i=0;i<s.size();i++){
				if(s[i]=='R'){val1++;if(val1<=num1) ans[i]='P';}
				if(s[i]=='P'){val2++;if(val2<=num2) ans[i]='S';}
				if(s[i]=='S'){val3++;if(val3<=num3) ans[i]='R';}
			}
			int xa=b-num1,xb=c-num2,xc=a-num3;
			for(int i=0;i<s.size();i++) if(ans[i]=='*'){
				if(xa>0){ans[i]='P';xa--;continue;}
				if(xb>0){ans[i]='S';xb--;continue;}
				if(xc>0){ans[i]='R';xc--;continue;}
			}
			for(int i=0;i<s.size();i++) cout<<ans[i];
			cout<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}