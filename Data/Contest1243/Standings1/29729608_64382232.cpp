#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		vector<pair<char,char> > q;
		int len;
		cin>>len;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<len;++i)
			if(a[i]!=b[i]) q.emplace_back(a[i],b[i]);
		if(q.size()!=2) cout<<"No"<<'\n'; 
		else if(q[0]==q[1]) cout<<"Yes"<<'\n';
		else cout<<"No"<<'\n';
	}
}
