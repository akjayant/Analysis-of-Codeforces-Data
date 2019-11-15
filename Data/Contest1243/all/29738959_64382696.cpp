#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){
	sync
	int t;
	cin >> t;
	while(t--){
		int n,count=0;
		string s,p;
		cin >> n >> s >> p;
		vector<int> v;
		for(int i=0;i<s.size();i++){
			if(s[i]!=p[i]){
				count++;
				v.push_back(i);
			}
		}
		if(count==0) cout << "Yes\n";
		else if(count==2){
			if(s[v[0]]==s[v[1]]&&p[v[0]]==p[v[1]]) cout << "Yes\n";
			else cout << "No\n";
		}
		else cout << "No\n";
	}
	return 0;
}