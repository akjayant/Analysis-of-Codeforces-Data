#include <bits/stdc++.h>

using namespace std;

void test_case(){
	int n; cin >> n;
	string s,t;
	cin >> s >> t;
	for(int i=0;i<26;i++){
		if((count(s.begin(),s.end(),(char)(i+'a'))+
				count(t.begin(),t.end(),(char)(i+'a')))&1){
			cout << "No" << endl;
			return;
		}
	}
	vector <pair<int,int>> ansl;
	cout << "Yes" << endl;
	for(int i=0;i<n;i++){
		if(s[i]==t[i]){
			continue;
		}
		for(int j=i+1;j<n;j++){
			if(s[j]==s[i]){
				//cout << j+1 << " " << i+1 << endl;
				ansl.push_back({j+1,i+1});
				swap(s[j],t[i]);
				break;
			}
		}
		if(s[i]==t[i]){
			continue;
		}
		for(int j=i+1;j<n;j++){
			if(t[j]==s[i]){
				//cout << j+1 << " " << j+1 << endl;
				ansl.push_back({j+1,j+1});
				swap(s[j],t[j]);
				//cout << j+1 << " " << i+1 << endl;
				ansl.push_back({j+1,i+1});
				swap(s[j],t[i]);
				break;
			}
		}
	}
	cout << ansl.size() << endl;
	for(int i=0;i<ansl.size();i++){
		cout << ansl[i].first << " " << ansl[i].second << endl;
	}
	return;
}

int main(){
	int t; cin >> t;
	while(t--){
		test_case();
	}
	return 0;
}