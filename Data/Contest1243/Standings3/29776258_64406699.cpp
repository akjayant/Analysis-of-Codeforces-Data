#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here       
	int k;
	cin>>k;
	while(k--){
		int n;
		cin>>n;
		string s, t;
		cin>>s>>t;
		int count[26] = {0};
		for(int i=0;i<n;i++){
			count[s[i]-'a']++;
			count[t[i]-'a']++;
		}
		int ans = 1;
		
		for(int i=0;i<26;i++){
			if(count[i]%2!=0){
				ans = 0;
				break;
			}
		}
		
		if(!ans){
			cout<<"No"<<endl;
			continue;
		}
		
		
		cout<<"Yes"<<endl;
		
		char temp;
		int m = 0;
		vector<int> ans1, ans2;
		
		for(int i=0;i<n;i++){
			if(s[i]==t[i]){
				continue;
			}
			bool done = false;
			for(int j=i+1;j<n;j++){
				if(done){
					break;
				}
				
				if(s[j]==s[i]){
					// cout<<j<<" "<<i<<endl;
					ans1.push_back(j);
					ans2.push_back(i);
					temp = s[j];
					s[j] = t[i];
					t[i] = temp;
					m++;
					done = true;
				}
				
				if(t[j]==s[i]){
					// cout<<j<<" "<<j<<endl;
					// cout<<j<<" "<<i<<endl;
					ans1.push_back(j);
					ans2.push_back(j);
					
					ans1.push_back(j);
					ans2.push_back(i);
					
					temp = t[j];
					t[j] = s[j];
					s[j] = t[i];
					t[i] = temp;
					
					m+=2;
					done = true;
				}
			}
		}
		cout<<m<<endl;
			for(int i=0;i<ans1.size();i++){
				cout<<ans1[i]+1<<" "<<ans2[i]+1<<endl;
		}
		
	}
		
	return 0;
}