#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
map<char, int>mp;
vector<pair<int, int> >ans;
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n; ans.clear();
		string s, t; cin>>s>>t;
		mp.clear();
		for(int i=0; i<n; i++){
			mp[s[i]]++;
			mp[t[i]]++;
		}
		bool impos=false;
		for(int i=0; i<26; i++){
			char tmp=(char)(i+'a');
			if(mp[tmp]&1){
				impos=true; break;
			}
		}
		if(impos){
			cout<<"No\n"; continue;
		}
		for(int i=0; i<n; i++){
			if(s[i]!=t[i]){
				//s jd tumpu
				bool udh=false;
				for(int j=i+1; j<n; j++){
					if(s[j]==s[i]){
						udh=true;
						ans.push_back({j, i});
						char tmp=s[j];
						s[j]=t[i];
						t[i]=tmp;
						break;
					}
				}
				if(udh) continue;
				for(int j=i+1; j<n; j++){
					if(t[j]==s[i]){
						ans.push_back({i+1, j});
						ans.push_back({i+1, i});
						char tmp=t[j];
						t[j]=s[i+1];
						s[i+1]=tmp;
						tmp=s[i+1];
						s[i+1]=t[i];
						t[i]=tmp;
						break;
					}
				}
			}
		}
		if(ans.size()>2*n){
			cout<<"No\n"; continue;
		}
		cout<<"Yes\n";
		cout<<ans.size()<<endl;
		for(int i=0; i<ans.size(); i++){
			cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
		}
	}
}