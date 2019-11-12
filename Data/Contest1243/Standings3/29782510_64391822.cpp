#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define p2(a,b) cout<<a<<" "<<b<<endl;
#define p3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;	
#define all(a) a.begin(),a.end()
#define M 1000000007

	
int getnext(string str, int st, int ch, int n){
	for(int i=st;i<n;i++){
		if(str[i]-'a'==ch) return i;
	}
	return -1;
}

int main(){
	fastio;
	int t,n;
	string s1,s2;
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2;
		int freq[26]={0};
		for(int i=0;i<n;i++){
			freq[s1[i]-'a']++;
			freq[s2[i]-'a']++;
		}
		bool ans=true;
		for(int i=0;i<26;i++){
			if(freq[i]%2) ans=false;
		}
		if(!ans){
			
			cout<<"No\n";
		}
		else {
			cout<<"Yes\n";
			vector<pair<int,int>> vec;
			for(int i=0;i<n;i++){
				if(s1[i]!=s2[i]){
					int x = getnext(s1, i+1, s1[i]-'a', n);
					if(x!=-1){
						vec.pb({x, i});
						char temp = s1[x];
						s1[x] = s2[i];
						s2[i] = temp;
					}
					else{
						int y = getnext(s2, i+1, s1[i]-'a', n);
						vec.pb({y,y});
						vec.pb({y,i});
						s2[y]=s1[y];
						s1[y]=s2[i];
						s2[i]=s1[i];
					}
				}
			}
			cout<<vec.size()<<"\n";
			for(int i=0;i<vec.size();i++){
				cout<<vec[i].first+1<<" "<<vec[i].second+1<<"\n";
			}
		}
	}
	return 0;
}