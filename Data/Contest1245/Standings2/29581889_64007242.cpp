#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	
	while(t --){
		int n,a,b,c;
		cin >> n >> a >> b >> c;
		
		string s;
		cin >> s;
		
		int h;
		if(n % 2 == 1) h = n / 2 + 1;
		else h = n / 2;
		
		int ra = 0,rb = 0,rc = 0;
		int la = 0,lb = 0,lc = 0;
		
		for(int i = 0;i < s.size();i++){
			if(s[i] == 'R') ra ++;
			else if(s[i] == 'P') rb ++;
			else rc ++;
		} 
		
		la = a - min(rc,a) , lb = b - min(ra,b) , lc = c - min(rb,c);
		a -= la , b -= lb , c -= lc;
		//cout << "| " << la << " " << lb << " " << lc << endl;
		
		if(min(rc,a) + min(ra,b) + min(rb,c) < h){
			cout << "NO" << endl;
			continue;
		} 
		cout << "YES" << endl;
		
		for(int i = 0;i < s.size();i++){
			if(s[i] == 'R'){
				if(b > 0) cout << "P" , b --;
				else if(la > 0) cout << "R" , la --;
				else cout << "S" , lc --;
			}
			if(s[i] == 'P'){
				if(c > 0) cout << "S" , c --;
				else if(la > 0) cout << "R" , la --;
				else cout << "P" , lb --;
			}
			if(s[i] == 'S' ){
				if(a > 0) cout << "R" , a --;
				else if(lc > 0) cout << "S" , lc --;
				else cout << "P" , lb --;
			}
		}
		cout << endl;
	}
}