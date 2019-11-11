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
	
	int t;
	
	cin>>t;
	
	while(t--){
		int n;
		int a, b, c;
		int A, B, C;
		int aa, bb, cc;
		int con = 0;
		string s;
		
		cin>>n;
		cin>>a>>b>>c;
		cin>>s;
		
		A = count(s.begin(), s.end(), 'R');
		B = count(s.begin(), s.end(), 'P');
		C = count(s.begin(), s.end(), 'S');
		
		con += min(A, b);
		con += min(B, c);
		con += min(C, a);
		
		bb = max(0ll, b - A);
		cc = max(0ll, c - B);
		aa = max(0ll, a - C);
		
		// aa = max(0ll, b - A);
		// bb = max(0ll, c - B);
		// cc = max(0ll, a - C);
		
		if(con*2 < n){
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
			for(int i = 0; i < n; i++){
				bool flag = false;
				if(s[i] == 'R') {
					if(b){
						cout<<"P";
						b--;
					} else flag = true;
				} else if(s[i] == 'P'){
					if(c){
						cout<<"S";
						c--;
					} else flag = true;
				} else if(s[i] == 'S'){
					if(a){
						cout<<"R";
						a--;
					} else flag = true;
				}
				
				if(flag){
					if(aa){
						cout<<"R";
						aa--;
						a--;
					}  else if(bb){
						cout<<"P";
						bb--;
						b--;
					} else {
						cout<<"S";
						cc--;
						c--;
					}
				}
			}
			
			cout<<endl;
		}
	}
	
	
	return 0;
}