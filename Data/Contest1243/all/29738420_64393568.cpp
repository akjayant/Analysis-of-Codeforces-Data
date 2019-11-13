#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define sec second
typedef long long ll;

int main(){
	int pp, pos;
	cin>>pp;
	while(pp--){
		int n;
		vector<pair<int ,int>> ans;
		cin>>n;
		string s, t;
		vector <char> vv;
		cin>>s>>t;
		map <int, int> mmap;
		for(int i = 0; i < n; i++){
			mmap[s[i]]++;
			vv.pb(s[i]);
		}
		for(int i = 0; i < n; i++){
			mmap[t[i]]++;
			vv.pb(t[i]);
		}
		int no = 0;
		for(int i = 'a'; i <= 'z'; i++){
			if(mmap[i]%2 == 0){
				
			}
			else{
				no = 1;
			}
		}
		
		if(no == 1){
			cout<<"No"<<'\n';
		}
		else{
			sort(vv.begin(), vv.end());
			char x;
			for(int i = 0; i < n; i++){
				x = s[i];
				
				vector <int> one, two;
				for(int j = i+1; j < n; j++){
					if(s[j] == x){
						one.pb(j);
					}
				}
				for(int j = i+1; j < n; j++){
					if(t[j] == x){
						two.pb(j);
					}
				}
				
				if(t[i] != x){
					if(one.size() != 0){
						char temp = s[one[0]];
						s[one[0]] = t[i];
						t[i] = temp;
						ans.pb({one[0], i});
						
					}
					else{
						ans.pb({n-1, two[0]});
						ans.pb({n-1, i});
						
						char temp = s[n-1];
						s[n-1] = t[two[0]];
						t[two[0]] = temp;
						
						temp = s[n-1];
						s[n-1] = t[i];
						t[i] = temp;
					}
				}
			}
			cout<<"Yes"<<'\n';
			cout<<ans.size()<<'\n';
			for(auto z: ans){
				cout<<z.f+1<<" "<<z.sec+1<<'\n';
			}
		}
	}
}
			