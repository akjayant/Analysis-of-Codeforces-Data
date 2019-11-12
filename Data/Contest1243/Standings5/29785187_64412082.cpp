#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		string a,b;
		cin>>a>>b;

		map<int,int>ma,mb;

		for(int i=0;i<n;i++){
			ma[a[i]-'a']++;
			ma[b[i]-'a']++;
		}

		bool f=true;
		for(int i=0;i<26;i++){
			if(ma[i]%2){
				f=false;
				break;
			}
		}

		if(f){
			int count=0;
			//cout<<"here<"<<endl;
			vector<pair<int,int> >p;
			for(int i=0;i<n-1;i++){
				if(a[i]!=b[i]){
					bool f=false;
					int j;
					for(j=i+1;j<n;j++){
						if(a[i]==a[j]){
							f=true;
							break;
						}
					}
					if(f){
						count++;
						p.push_back({j,i});
						swap(a[j],b[i]);
					}else{
						for(j=i+1;j<n;j++){
							if(a[i]==b[j]){
								break;
							}
						}
						count+=2;
						p.push_back({j,j});
						p.push_back({j,i});
						swap(a[j],b[j]);
						swap(a[j],b[i]);
					}
				}
			}
			if(count<=2*n){
				cout<<"Yes"<<endl;
				cout<<count<<endl;
				for(auto uj:p){
					cout<<uj.first+1<<" "<<uj.second+1<<endl;
				}
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
	}	
}