#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>

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
	
	int n;
	int maximum = -1, a, b;
	string s;
	
	cin>>n;
	
	cin>>s;
	
	if(count(s.begin(), s.end(), ')') != count(s.begin(), s.end(), '(')){
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			swap(s[i], s[j]);
			
			stack<int> sta;
			int con = 0;
			
			for(int k = 0; k < n; k++){
				if(s[k] == '('){
					sta.push(1);
				} else {
					int temp = -1;
					
					while(true){
						if(sta.size()){
							temp = sta.top(); sta.pop();

							if(temp == 1){
								sta.push(2);
								break;
							} else {
								
							}
						} else {
							con++;
							temp = -1;
							break;
						}
					}
				}
			}
			for(int k = 0; k < con; k++){
				int temp = -1;
				while(true){
					if(sta.size()){
						temp = sta.top(); sta.pop();

						if(temp == 1){
							sta.push(2);
							break;
						} else {
							
						}
					} else {
						con++;
						temp = -1;
						break;
					}
				}
			}
			
			
			int X = sta.size();
			// cout<<"i = "<<i<<" j = "<<j<<" sta "<<sta.size()<<" s = "<<s<<" max = "<<maximum<<endl;
			
			// cout<<maximum<<" < "<<sta.size()<<endl;
			if(maximum < X){
				maximum = X;
				// cout<<maximum<<" <> "<<sta.size()<<endl;
				a = i+1, b = j+1;
			}
			
			swap(s[i], s[j]);
		}
	}
	
	cout<<maximum<<endl;
	cout<<a<<" "<<b<<endl;
	
	
	return 0;
}