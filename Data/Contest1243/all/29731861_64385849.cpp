#include<bits/stdc++.h>

using namespace std;


bool f(int &n,string s,string t){
	vector<int> v;
	for(int i = 0;i<n;i++)if(s[i]!=t[i])v.push_back(i);
	if(v.size()!=2)return false;
	if((s[v[0]]!=s[v[1]]) || (t[v[0]]!=t[v[1]]))return false;
	return true;
}

int main(){
	int k; cin>>k;
	for(int kn = 0;kn<k;kn++){
		int n; cin>>n;
		string s,t; cin>>s>>t;
		bool ans = f(n,s,t);
		cout<<(ans?"YES":"NO")<<"\n";
	}
	return 0;
}
