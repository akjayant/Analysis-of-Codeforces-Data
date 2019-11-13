#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string s, t; cin>>s>>t;
		int i1=-1, i2=-1; bool impos=false;
		for(int i=0; i<n; i++){
			if(s[i]!=t[i]){
				if(i1==-1) i1=i;
				else if(i2==-1) i2=i;
				else{
					impos=true; break;
				}
			}
		}
		if(impos || i1==-1 || i2==-1){
			cout<<"No\n"; continue;
		}
		if(t[i1]==t[i2] && s[i2]==s[i1]){
			cout<<"Yes\n"; continue;
		}
		cout<<"No\n";
	}
	return 0;
}