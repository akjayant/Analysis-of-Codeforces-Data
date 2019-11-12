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



signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	int k;
	
	cin>>k;
	
	for(int _ = 0; _ < k; _++){
		int n;
		string s, t;
		
		cin>>n;
		
		cin>>s>>t;
		
		if(s == t) cout<<"Yes"<<endl;
		else {
			int con = 0, a = -1, b = 0;
			
			for(int i = 0; i < s.size(); i++){
				if(s[i] != t[i]){
					con++;
					if(a == -1) a = i;
					b = i;
				}
			}
			
			if(con == 2){
				char temp = s[a];
				s[a] = t[b];
				t[b] = temp;
				
				if(s == t) cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
				
			} else cout<<"No"<<endl;
		}
	}
	
	
	return 0;
}