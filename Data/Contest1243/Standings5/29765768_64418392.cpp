#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef pair<int,int> par;

set<int> T1[26];
set<int> T2[26];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(NULL);
	int t,n,cond,x,y,i;
	string cad1, cad2;
	vector<int> alp1(26), alp2(26);
	vector<par> ans;
	set<int>::iterator it;
	cin>>t;
	while(t--){
		cin>>n>>cad1>>cad2;
		for(i=0; i<26; i++){
			alp1[i] = 0;
			alp2[i] = 0;
		}
		for(i=0; i<n; i++){
			alp1[cad1[i]-'a']++;
			alp2[cad2[i]-'a']++;
		}
		cond = 1;
		for(i=0; i<26; i++){
			if((alp1[i] + alp2[i]) % 2 == 1)
			cond = 0;
		}
		if(cond == 1){
			cout<<"YES"<<endl;
			for(i=0; i<n; i++){
				T1[cad1[i]-'a'].insert(i);
				T2[cad2[i]-'a'].insert(i);
			}
			for(i=0; i<n; i++){
				if(cad1[i] != cad2[i]){
					it = T1[cad1[i]-'a'].lower_bound(i+1);
					if(it != T1[cad1[i]-'a'].end()){
						x = *it;
						ans.push_back(par(x,i));
						T1[cad1[i]-'a'].erase(it);
						T1[cad2[i]-'a'].insert(x);

						it = T2[cad2[i]-'a'].find(i);
						T2[cad2[i]-'a'].erase(it);
						T2[cad1[i]-'a'].insert(i);

						char temp = cad1[x];
						cad1[x] = cad2[i];
						cad2[i] = temp;
					}
					else{
						it = T2[cad1[i]-'a'].lower_bound(i+1);
						x = *it;
						// .......1
						ans.push_back(par(x,x));
					/*	cout<<".";
						if(it != T2[cad1[i]-'a'].end())
						cout<<*it<<endl;*/
						T2[cad1[i]-'a'].erase(it);
						T2[cad1[x]-'a'].insert(x);

						it = T1[cad1[x]-'a'].find(x);
						T1[cad1[x]-'a'].erase(it);
						T1[cad1[i]-'a'].insert(x);

						char temp = cad1[x];
						cad1[x] = cad2[x];
						cad2[x] = temp;

						// .......2
						ans.push_back(par(x,i));
						it = T1[cad1[i]-'a'].find(x);
						T1[cad1[i]-'a'].erase(it);
						T1[cad2[i]-'a'].insert(x);

						it = T2[cad2[i]-'a'].find(i);
						T2[cad2[i]-'a'].erase(it);
						T2[cad1[i]-'a'].insert(i);

						temp = cad1[x];
						cad1[x] = cad2[i];
						cad2[i] = temp;
					}
				}
			}
			cout<<ans.size()<<endl;
			for(i=0; i<ans.size(); i++){
				cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
			}
		}
		else
		cout<<"NO"<<endl;
		ans.clear();
		for(i=0; i<26; i++){
			T1[i].clear();
			T2[i].clear();
		}
	}
}