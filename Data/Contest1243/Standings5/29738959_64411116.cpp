#include<bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main(){
	sync
	int t;
	cin >> t;
	while(t--){
		int n,flag=0,count=0,k=0;
		string s,p;
		cin >> n >> s >> p;
		vector<int> a(26,0);
		for(int i=0;i<n;i++){
			a[s[i]-'a']++;
			a[p[i]-'a']++;
		}
		for(int i=0;i<26;i++){
			if(a[i]%2!=0){
				flag=1;
				break;
			}
		}
		if(flag==1){
			cout << "No\n";
			continue;
		}
		vector<pair<int,int>> v;
		while(k<n){
			if(s[k]==p[k]){
				k++;
				continue;
			}
			for(int i=k;i<n;i++){
				int flag1=0;
				for(int j=i+1;j<n;j++){
					if(s[i]==s[j]){
						v.push_back({j+1,i+1});
						s[j]=p[i];
						p[i]=s[i];
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					for(int j=i+1;j<n;j++){
						if(s[i]==p[j]){
							v.push_back({j+1,j+1});
							v.push_back({j+1,i+1});
							char temp=s[j];
							s[j]=p[j];
							p[j]=temp;
							temp=s[j];
							s[j]=p[i];
							p[i]=temp;
							break;
						}
					}
				}
			}
			k++;
		}
		cout << "Yes\n" << v.size() << "\n";
		for(int i=0;i<v.size();i++){
			cout << v[i].first << " " << v[i].second << "\n";
		}
	}
	return 0;
}