#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

void solve(){
	int n; cin>>n;
	string s1, s2;
	cin>>s1>>s2;
	map<char, int> m;
	for(int i = 0; i < s1.length(); i++){
		m[s1[i]]++;
		m[s2[i]]++;
	}
	for(auto mm : m){
		if(mm.second % 2 != 0){
			cout<<"No\n";
			return;
		}
	}
	cout<<"Yes\n";
	vector<pair<int,int> > ans;
	for(int i = 0; i < s1.length(); i++){
		bool flag = false;
		// cout<<s1<<endl;
		// cout<<s2<<endl;
		// cout<<"i="<<i<<endl;
		for(int j = i+1; j < s1.length(); j++){
			if(s1[i] == s1[j]){
				// cout<<"first swap\n";
				flag = true;
				char temp = s2[i];
				s2[i] = s1[j];
				s1[j] = temp;
				ans.push_back({j+1,i+1});
				break;
			}
		}
		if(flag) continue;
		if(s2[i] == s1[i]) continue;
		for(int j = i+1; j < s1.length(); j++){
			if(s2[j] == s1[i]){
				// cout<<"second swap\n";
				char temp = s1[i+1];
				s1[i+1] = s2[j];
				s2[j] = temp;
				ans.push_back({i+2,j+1});

				temp = s2[i];
				s2[i] = s1[i+1];
				s1[i+1] = temp;
				ans.push_back({i+2, i+1});

				break;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto p : ans){
		cout<<p.first<<" "<<p.second<<endl;
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}