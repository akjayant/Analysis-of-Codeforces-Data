#include <bits/stdc++.h>

using namespace std;

void test_case(){
	int n; cin >> n;
	int a,b,c,na=0,nb=0,nc=0; cin >> a >> b >> c;
	string s; cin >> s;
	for(auto ch:s){
		if(ch=='R'){
			na++;
		}
		else if(ch=='P'){
			nb++;
		}
		else{
			nc++;
		}
	}
	if(min(b,na)+min(c,nb)+min(a,nc) >=(n+1)/2){
		cout << "YES" << endl;
		string ans;
		for(auto ch:s){
			if(ch=='R'){
				if(b){
					b--;
					ans+='P';
				}
				else
					ans+='$';
			}
			if(ch=='P'){
				if(c){
					c--;
					ans+='S';
				}
				else 
					ans+='$';
			}
			if(ch=='S'){
				if(a){
					a--;
					ans+='R';
				}
				else
					ans+='$';
			}
		}
		for(auto &ch:ans){
			if(ch=='$'){
				if(a){
					ch='R';
					a--;
				}
				else if(b){
					ch='P';
					b--;
				}
				else{
					ch='S';
					c--;
				}
			}
		}
		cout << ans << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return;
}

int main(){
	int t; cin >> t;
	while(t--){
		test_case();
	}
	return 0;
}