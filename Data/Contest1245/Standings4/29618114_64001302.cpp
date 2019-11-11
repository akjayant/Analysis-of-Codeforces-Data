#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

const int MN = 1003;

void solve(){
	int n,r,p,s;
	cin>>n>>r>>p>>s;
	char res[MN];
	char t,wins=0;
	for(int i=0; i<n; ++i){
		cin>>t;
		res[i]='?';
		if(t=='R'&&p){
			--p;
			++wins;
			res[i]='P';
		}
		if(t=='P'&&s){
			--s;
			++wins;
			res[i]='S';
		}    	
if(t=='S'&&r){
			--r;
			++wins;
			res[i]='R';
		}
	}
	if(wins*2>=n){
		cout<<"YES\n";
		for(int i=0; i<n; ++i){
			if(res[i]=='?'){
				if(p){--p;cout<<'P';}
				else if(s){--s;cout<<'S';}
				else if(r){--r;cout<<'R';}
			} else {
				cout<<res[i];
			}
		}
	} else cout<<"NO";
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}