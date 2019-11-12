#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;

		int pos=0;
		map<int,int>mp;
		vector<pair<int,int> >v;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				pos++;
				v.push_back({a[i]-'a',b[i]-'a'});
			}
		}

		if(pos==2){
			int cnt=0;
			if(v[0].first==v[1].first && v[0].second==v[1].second)
				cnt=2;
			if(cnt==2){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}	
}