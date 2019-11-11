#include <bits/stdc++.h>
using namespace std;
const int N =1e5+9;
const int mod = 1e9+7;
typedef long long ll;


int main() {  
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,a,b,n,c;
    string s;
    cin>>t;
    while(t--){
    	cin>>n>>a>>b>>c>>s;
    	int cr=0,cp=0,cs=0;
    	for(int i=0;i<s.length();i++){
    		if(s[i]=='R') cr++;
    		else if(s[i]=='P') cp++;
    		else cs++;
		}
		int mx = min(a,cs)+min(b,cr)+min(c,cp);
		bool ans = false;
		if(mx>=(n+1)/2) ans = true;
		if(ans) cout<<"YES\n";
		else cout<<"NO\n";
		if(ans){
			char op[s.length()];
			for(int i=0;i<s.length();i++)
				op[i]='0';
			for(int i=0;i<s.length();i++){
				if(s[i]=='R'){
					if(b) b--,op[i]='P';
				}
				else if(s[i]=='P'){
					if(c) c--,op[i]='S';
				}
				else if(s[i]=='S'){
					if(a) a--,op[i]='R';
				}
			}
			for(int i=0;i<s.length();i++){
				if(op[i]=='0'){
					if(a) a--,op[i]='R';
					else if(b) b--,op[i]='P';
					else c--,op[i]='S';
				}				
			}
			for(int i=0;i<s.length();i++) cout<<op[i];
			cout<<"\n";
		}
	}
}