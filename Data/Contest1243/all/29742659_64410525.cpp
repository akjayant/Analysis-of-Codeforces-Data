#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		int asci[26];
		memset(asci,0,sizeof(asci));
		for(int i=0;i<n;i++){
			int kar = s[i]-'a';
			asci[kar]++;
			kar = t[i]-'a';
			asci[kar]++;
		}
		int flag=0;
		for(int i=0;i<26;i++){
			if(asci[i]%2!=0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout<<"No\n";
			continue;
		}
		string a,b;
		vector<int> x,y;
		for(int i=0;i<n;i++){
			if(s[i]!=t[i]){
				a+=s[i];
				x.push_back(i);
				b+=t[i];
				y.push_back(i);
			}
		}
		vector<pair<int,int > > ans;
		for(int i=0;i<a.size();i++){
			char ch = b[i];
			if(a[i]==b[i])	continue;
			flag=0;
			for(int j=i+1;j<a.size();j++){
				if(a[j]==a[i]){
					flag = 1;
					b[i] = a[j];
					a[j] = ch;
					ans.push_back({x[j],y[i]});
					break; 
				}
			}
			if(flag==0){
				for(int j=i+1;j<a.size();j++){
					if(b[j]==a[i]){
						ch = a[i+1];
						a[i+1] = b[j];
						b[j] = ch;
						ans.push_back({x[i+1],y[j]});
						ch = b[i];
						b[i] = a[i+1];
						a[i+1] = ch;
						ans.push_back({x[i+1],y[i]}); 
						break;
					}
				}
			}
		}
		cout<<"Yes\n";
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first+1<<" "<<ans[i].second+1<<"\n";
		}
	}
	return 0;
}