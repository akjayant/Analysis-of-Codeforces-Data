#include<bits/stdc++.h>

using namespace std;

pair<bool,vector<pair<int,int>>>f(int& n, string&s, string&t){
	vector<pair<int,int>> v;
	for(int i = 0;i<n;i++){
		if(s[i]==t[i])continue;
		for(int j = i+1;j<n;j++){
			if(s[j]==s[i]){
				v.push_back(make_pair(j,i));
				char tmp = t[i];
				t[i] = s[j];
				s[j] = tmp;
				break;
			}
			if(t[j] == s[i]){
				v.push_back(make_pair(j,j));
				char tmp = t[j];
				t[j] = s[j];
				s[j] = tmp;
				v.push_back(make_pair(j,i));
				tmp = t[i];
				t[i] = s[j];
				s[j] = tmp;
				break;
			}
			
		}
		
	}
	bool ans = true;
	for(int i = 0;i<n;i++)if(s[i]!=t[i])ans = false;
	return make_pair(ans,v);
}

int main(){
	int k; cin>>k;
	for(int kn = 0;kn<k;kn++){
		int n; cin>>n;
		string s,t;
		cin>>s>>t;
		pair<bool,vector<pair<int,int>>> r = f(n,s,t);
		if(r.first){
			cout<<"YES"<<"\n";
			vector<pair<int,int>> v = r.second;
			cout<<v.size()<<"\n";
			for(int i = 0;i<v.size();i++)cout<<v[i].first+1<<" "<<v[i].second+1<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}
