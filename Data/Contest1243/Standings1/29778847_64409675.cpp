#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

#define int long long
#define endl "\n"

const long long INF = (long long)1e18;
const long long MOD = 1'000'000'007; 

string yn(bool f){return f?"Yes":"No";}
string YN(bool f){return f?"YES":"NO";}

void swa(string &s, string & t, int i, int j){
	char a = s[i];
	s[i] = t[j];
	t[j] = a;
}

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	const int NUM = 26;
	
	int k;
	
	cin>>k;
	
	for(int _ = 0; _ < k; _++){
		int n;
		bool flag = true;
		string s, t;
		vector<pair<int,int>> ans;
		int con[NUM] = {}, con1[NUM] = {}, con2[NUM] = {};
		
		cin>>n;
		
		cin>>s>>t;
		
		for(int i = 0; i < n; i++){
			con[s[i] - 'a']++;
			con[t[i] - 'a']++;
			con1[s[i] - 'a']++;
			con2[t[i] - 'a']++;
		}
		
		
		
		for(int i = 0; i < NUM; i++){
			if(con[i]%2){
				flag = false;
				break;
			}
		}
		
		if(!flag){
			cout<<"No"<<endl;
		} else {
			cout<<"Yes"<<endl;
			
			for(int i = 0; i < n; i++){
				if(s[i] == t[i]) continue;
				bool flag = false;
				for(int j = i + 1; j < n; j++){
					if(s[i] == s[j]){
						swa(s,t,j,i);
						ans.push_back(make_pair(j,i));
						flag = true;
						break;
					}
					
				}
				if(flag) continue;
				for(int j = i + 1; j < n; j++){
					if(s[i] == t[j]){
						swa(s,t,j,j);
						swa(s,t,j,i);
						ans.push_back(make_pair(j,j));
						ans.push_back(make_pair(j,i));
						flag = true;
						break;
					}
					
				}
				
			}
			// cout<<"<>"<<endl;
			// cout<<s<<endl;
			// cout<<t<<endl;
			
			cout<<ans.size()<<endl;
			
			for(pair<int,int> p : ans){
				cout<<p.first+1<<" "<<p.second+1<<endl;
			}
		}
		
	}
	
	
	return 0;
}