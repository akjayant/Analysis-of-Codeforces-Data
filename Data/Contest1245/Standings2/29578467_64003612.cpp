#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a,b,c;
		cin>>a>>b>>c;
		string s;
		cin>>s;
		vector<char>ans;
		int aa=0,bb=0,cc=0;
		int win=0;
		for(int i=0;i<s.size();++i){
			switch(s[i]){
				case 'R':
					++bb;break;
				case 'P':
					++cc;break;
				case 'S':
					++aa;break;
			}
		}
		int t1=a-aa,t2=b-bb,t3=c-cc;
		int num=min(a,aa)+min(b,bb)+min(c,cc);
		if(num<(n+1)/2){
			cout<<"NO"<<'\n';
		}
		else{
			cout<<"YES\n";
			for(int i=0;i<s.size();++i){
			switch(s[i]){
				case 'R':
					if(b) --b,cout<<"P";
					else {
						if(t1>0) --t1,cout<<"R";
						else --t3,cout<<"S";
					}
					break;
				case 'P':
					if(c) --c,cout<<"S";
					else {
						if(t1>0) --t1,cout<<"R";
						else --t2,cout<<"P";
					}
					break;
				case 'S':
					if(a) --a,cout<<"R";
					else {
						if(t2>0) --t2,cout<<"P";
						else --t3,cout<<"S";
					}
					break;
			}
			}
			cout<<'\n';
		}
		
	}
	return 0;
}

