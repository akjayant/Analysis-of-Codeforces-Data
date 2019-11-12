#include <bits/stdc++.h>
using namespace std;
int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		string s,t;
		cin >> s >> t;
		int f[26]={0};
		for(int i=0;i<n;i++){
			f[s[i]-'a']++;
			f[t[i]-'a']++;
		}
		int flag=0;
		for(int i=0;i<26;i++){
			if(f[i]%2){
				flag=1;
				break;
			}
		}
		if(flag){
			cout << "No" << endl;
			continue;
		}
		vector <pair<int,int> > v;
		for(int i=0;i<n;i++){
			if(s[i]==t[i])
				continue;
			int k=-1;
			for(int j=i+1;j<n;j++){
				if(s[i]==s[j]){
					k=j;
					break;
				}
			}
			if(k!=-1){
				v.push_back({k,i});
				swap(s[k],t[i]);
				continue;
			}
			for(int j=i+1;j<n;j++){
				if(s[i]==t[j]){
					k=j;
					break;
				}
			}
			if(k!=-1){
				v.push_back({k,k});
				v.push_back({k,i});
				swap(s[k],t[k]);
				swap(s[k],t[i]);
			}
		}
		cout << "Yes" << endl;
		cout << v.size() << endl;
		for(int i=0;i<v.size();i++)
			cout << v[i].first+1 << " " << v[i].second+1 << endl;
	}
}