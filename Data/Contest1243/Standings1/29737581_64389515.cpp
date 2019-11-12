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
	bool flag=0;
	for(int i=0;i<n;i++){
		if(flag){
			break;
		}
		if(s[i]==t[i]){
			continue;
		}
		for(int j=i+1;j<n;j++){
			if((s[j]==s[i]) && (s[j]!=t[j])){
				swap(s[j],t[i]);
				flag=1;
				break;
			}
		}
		if(s[i]!=t[i]){
			break;
		}
	}
	if(s==t){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
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